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
                { "entity_save" : { "data" : [ "commerce-order:owner:field-referred-by-level-1" ] } }
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
                { "entity_save" : { "data" : [ "commerce-order:owner:field-referred-by-level-2" ] } }
              ]
            }
          ]
        }
      ]
    }
  }');
  return $items;
}
