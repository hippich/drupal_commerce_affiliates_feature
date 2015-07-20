<?php
/**
 * @file
 * commerce_affiliates_feature.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_affiliates_feature_default_rules_configuration() {
  $items = array();
  $items['rules_apply_commissions_to_affiliates'] = entity_import('rules_config', '{ "rules_apply_commissions_to_affiliates" : {
      "LABEL" : "Apply commissions to affiliates",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Redirecto" ],
      "REQUIRES" : [ "rules", "rules_conditional", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-order" ], "field" : "field_level_1_commission" } },
        { "entity_has_field" : { "entity" : [ "commerce-order" ], "field" : "field_level_2_commission" } }
      ],
      "DO" : [
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "commerce-order:commerce-order-total:amount-decimal" ],
              "op" : "*",
              "input_2" : "0.1"
            },
            "PROVIDE" : { "result" : { "affiliate_level_1_commission" : "Affiliate Level 1 Commission" } }
          }
        },
        { "data_calc" : {
            "USING" : {
              "input_1" : [ "affiliate-level-1-commission" ],
              "op" : "*",
              "input_2" : "0.2"
            },
            "PROVIDE" : { "result" : { "affiliate_level_2_commission" : "Affiliate Level 2 Commission" } }
          }
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "NOT data_is_empty" : { "data" : [ "commerce-order:owner:field-referred-by-level-1" ] } },
              "DO" : [
                { "CONDITIONAL" : [
                    {
                      "IF" : { "data_is_empty" : { "data" : [ "commerce-order:owner:field-referred-by-level-1:field-commission" ] } },
                      "DO" : [
                        { "data_set" : {
                            "data" : [ "commerce-order:owner:field-referred-by-level-1:field-commission" ],
                            "value" : "0"
                          }
                        }
                      ]
                    }
                  ]
                },
                { "data_calc" : {
                    "USING" : {
                      "input_1" : [ "affiliate-level-1-commission" ],
                      "op" : "+",
                      "input_2" : [ "commerce-order:owner:field-referred-by-level-1:field-commission" ]
                    },
                    "PROVIDE" : { "result" : { "affiliate_level_1_new_total" : "Affiliate Level 1 New Total" } }
                  }
                },
                { "data_set" : {
                    "data" : [ "commerce-order:owner:field-referred-by-level-1:field-commission" ],
                    "value" : [ "affiliate-level-1-new-total" ]
                  }
                },
                { "entity_save" : { "data" : [ "commerce-order:owner:field-referred-by-level-1" ] } },
                { "data_set" : {
                    "data" : [ "commerce-order:field-level-1-commission" ],
                    "value" : [ "affiliate-level-1-commission" ]
                  }
                },
                { "entity_save" : { "data" : [ "commerce-order" ] } }
              ]
            }
          ]
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "NOT data_is_empty" : { "data" : [ "commerce-order:owner:field-referred-by-level-2" ] } },
              "DO" : [
                { "CONDITIONAL" : [
                    {
                      "IF" : { "data_is_empty" : { "data" : [ "commerce-order:owner:field-referred-by-level-2:field-commission" ] } },
                      "DO" : [
                        { "data_set" : {
                            "data" : [ "commerce-order:owner:field-referred-by-level-2:field-commission" ],
                            "value" : "0"
                          }
                        }
                      ]
                    }
                  ]
                },
                { "data_calc" : {
                    "USING" : {
                      "input_1" : [ "affiliate-level-2-commission" ],
                      "op" : "+",
                      "input_2" : [ "commerce-order:owner:field-referred-by-level-2:field-commission" ]
                    },
                    "PROVIDE" : { "result" : { "affiliate_level_2_new_total" : "Affiliate Level 2 New Total" } }
                  }
                },
                { "data_set" : {
                    "data" : [ "commerce-order:owner:field-referred-by-level-2:field-commission" ],
                    "value" : [ "affiliate-level-2-new-total" ]
                  }
                },
                { "entity_save" : { "data" : [ "commerce-order:owner:field-referred-by-level-2" ] } },
                { "data_set" : {
                    "data" : [ "commerce-order:field-level-2-commission" ],
                    "value" : [ "affiliate-level-2-commission" ]
                  }
                },
                { "entity_save" : { "data" : [ "commerce-order" ] } }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_save_affiliate_uids_to_newly_created_user_profile'] = entity_import('rules_config', '{ "rules_save_affiliate_uids_to_newly_created_user_profile" : {
      "LABEL" : "Save affiliate UIDs to newly created User Profile",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules_session_vars", "rules", "rules_conditional", "commerce" ],
      "ON" : { "user_insert" : [] },
      "IF" : [ { "session_key_exists" : { "data_key" : "commerce_affiliate_uid" } } ],
      "DO" : [
        { "load_data_from_session" : {
            "USING" : { "data_key" : "commerce_affiliate_uid" },
            "PROVIDE" : { "loaded_session_data" : { "session_affiliate_uid" : "Affiliate UID from session" } }
          }
        },
        { "data_convert" : {
            "USING" : { "type" : "integer", "value" : [ "session-affiliate-uid" ] },
            "PROVIDE" : { "conversion_result" : { "affiliate_uid" : "Affiliate UID" } }
          }
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "entity_exists" : { "type" : "user", "property" : "uid", "value" : [ "affiliate-uid" ] } },
              "DO" : [
                { "entity_fetch" : {
                    "USING" : { "type" : "user", "id" : [ "affiliate-uid" ] },
                    "PROVIDE" : { "entity_fetched" : { "affiliate_user_1" : "Affiliate $user (level 1)" } }
                  }
                },
                { "data_set" : {
                    "data" : [ "account:field-referred-by-level-1" ],
                    "value" : [ "affiliate-user-1" ]
                  }
                },
                { "CONDITIONAL" : [
                    {
                      "IF" : { "NOT data_is_empty" : { "data" : [ "affiliate-user-1:field-referred-by-level-1" ] } },
                      "DO" : [
                        { "data_set" : {
                            "data" : [ "account:field-referred-by-level-2" ],
                            "value" : [ "affiliate-user-1:field-referred-by-level-1" ]
                          }
                        }
                      ]
                    }
                  ]
                },
                { "entity_save" : { "data" : [ "account" ] } }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_store_affiliate_id_in_session'] = entity_import('rules_config', '{ "rules_store_affiliate_id_in_session" : {
      "LABEL" : "Store affiliate id in session",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules_url_argument", "rules_session_vars", "rules" ],
      "ON" : { "init" : [] },
      "IF" : [
        { "rules_url_argument_argument_exists" : { "argument" : "aff" } },
        { "NOT session_key_exists" : { "data_key" : "commerce_affiliate_uid" } }
      ],
      "DO" : [
        { "rules_url_argument_rules_action_get_argument_from_url" : {
            "USING" : { "type" : "decimal", "argument_name" : "aff" },
            "PROVIDE" : { "argument_from_url" : { "affiliate_argument_from_url" : "Affiliate argument from URL" } }
          }
        },
        { "add_data_to_session" : {
            "data_key" : "commerce_affiliate_uid",
            "data_value" : [ "affiliate-argument-from-url" ]
          }
        }
      ]
    }
  }');
  return $items;
}
