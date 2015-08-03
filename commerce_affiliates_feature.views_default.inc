<?php
/**
 * @file
 * commerce_affiliates_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_affiliates_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'affiliates_activity';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_order';
  $view->human_name = 'Affiliates Activity';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Affiliates Activity';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access to affiliate feature';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['contextual_filters_or'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'You have no affiliate activity yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Commerce Order: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  /* Field: Commerce Order: Level 1 Commission */
  $handler->display->display_options['fields']['field_level_1_commission']['id'] = 'field_level_1_commission';
  $handler->display->display_options['fields']['field_level_1_commission']['table'] = 'field_data_field_level_1_commission';
  $handler->display->display_options['fields']['field_level_1_commission']['field'] = 'field_level_1_commission';
  $handler->display->display_options['fields']['field_level_1_commission']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_level_1_commission']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Commerce Order: Level 2 Commission */
  $handler->display->display_options['fields']['field_level_2_commission']['id'] = 'field_level_2_commission';
  $handler->display->display_options['fields']['field_level_2_commission']['table'] = 'field_data_field_level_2_commission';
  $handler->display->display_options['fields']['field_level_2_commission']['field'] = 'field_level_2_commission';
  $handler->display->display_options['fields']['field_level_2_commission']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_level_2_commission']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: User: Referred By (Level 1) */
  $handler->display->display_options['fields']['field_referred_by_level_1']['id'] = 'field_referred_by_level_1';
  $handler->display->display_options['fields']['field_referred_by_level_1']['table'] = 'field_data_field_referred_by_level_1';
  $handler->display->display_options['fields']['field_referred_by_level_1']['field'] = 'field_referred_by_level_1';
  $handler->display->display_options['fields']['field_referred_by_level_1']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_referred_by_level_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_referred_by_level_1']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_referred_by_level_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: User: Referred By (Level 2) */
  $handler->display->display_options['fields']['field_referred_by_level_2']['id'] = 'field_referred_by_level_2';
  $handler->display->display_options['fields']['field_referred_by_level_2']['table'] = 'field_data_field_referred_by_level_2';
  $handler->display->display_options['fields']['field_referred_by_level_2']['field'] = 'field_referred_by_level_2';
  $handler->display->display_options['fields']['field_referred_by_level_2']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_referred_by_level_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_referred_by_level_2']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_referred_by_level_2']['settings'] = array(
    'link' => 0,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Commission';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if ($row->field_referred_by_level_1 == $handler->view->args[0]) {
  echo \'$\' . $row->field_level_1_commission;
} else {
  echo \'$\' . $row->field_level_2_commission;
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Contextual filter: User: Referred By (Level 1) (field_referred_by_level_1) */
  $handler->display->display_options['arguments']['field_referred_by_level_1_target_id']['id'] = 'field_referred_by_level_1_target_id';
  $handler->display->display_options['arguments']['field_referred_by_level_1_target_id']['table'] = 'field_data_field_referred_by_level_1';
  $handler->display->display_options['arguments']['field_referred_by_level_1_target_id']['field'] = 'field_referred_by_level_1_target_id';
  $handler->display->display_options['arguments']['field_referred_by_level_1_target_id']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['field_referred_by_level_1_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_referred_by_level_1_target_id']['breadcrumb'] = '<none>';
  $handler->display->display_options['arguments']['field_referred_by_level_1_target_id']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['field_referred_by_level_1_target_id']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['field_referred_by_level_1_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_referred_by_level_1_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_referred_by_level_1_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: User: Referred By (Level 2) (field_referred_by_level_2) */
  $handler->display->display_options['arguments']['field_referred_by_level_2_target_id']['id'] = 'field_referred_by_level_2_target_id';
  $handler->display->display_options['arguments']['field_referred_by_level_2_target_id']['table'] = 'field_data_field_referred_by_level_2';
  $handler->display->display_options['arguments']['field_referred_by_level_2_target_id']['field'] = 'field_referred_by_level_2_target_id';
  $handler->display->display_options['arguments']['field_referred_by_level_2_target_id']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['field_referred_by_level_2_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_referred_by_level_2_target_id']['breadcrumb'] = '<none>';
  $handler->display->display_options['arguments']['field_referred_by_level_2_target_id']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['field_referred_by_level_2_target_id']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['field_referred_by_level_2_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_referred_by_level_2_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_referred_by_level_2_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Date: Date (commerce_order) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['value']['min'] = '2015-08-02';
  $handler->display->display_options['filters']['date_filter']['value']['max'] = '2015-08-02';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'From';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'commerce_order.created' => 'commerce_order.created',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Filter criterion: Date: Date (commerce_order) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'To';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'commerce_order.created' => 'commerce_order.created',
  );
  $handler->display->display_options['filters']['date_filter_1']['date_method'] = 'AND';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/affiliates-activity';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Affiliates Activity';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['affiliates_activity'] = $view;

  return $export;
}
