<?php
/**
 * @file
 * commerce_affiliates_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function commerce_affiliates_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_commission'.
  $permissions['create field_commission'] = array(
    'name' => 'create field_commission',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_paid'.
  $permissions['create field_paid'] = array(
    'name' => 'create field_paid',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_referred_by_level_1'.
  $permissions['create field_referred_by_level_1'] = array(
    'name' => 'create field_referred_by_level_1',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_referred_by_level_2'.
  $permissions['create field_referred_by_level_2'] = array(
    'name' => 'create field_referred_by_level_2',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_commission'.
  $permissions['edit field_commission'] = array(
    'name' => 'edit field_commission',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_paid'.
  $permissions['edit field_paid'] = array(
    'name' => 'edit field_paid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_referred_by_level_1'.
  $permissions['edit field_referred_by_level_1'] = array(
    'name' => 'edit field_referred_by_level_1',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_referred_by_level_2'.
  $permissions['edit field_referred_by_level_2'] = array(
    'name' => 'edit field_referred_by_level_2',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_commission'.
  $permissions['edit own field_commission'] = array(
    'name' => 'edit own field_commission',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_paid'.
  $permissions['edit own field_paid'] = array(
    'name' => 'edit own field_paid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_referred_by_level_1'.
  $permissions['edit own field_referred_by_level_1'] = array(
    'name' => 'edit own field_referred_by_level_1',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_referred_by_level_2'.
  $permissions['edit own field_referred_by_level_2'] = array(
    'name' => 'edit own field_referred_by_level_2',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_commission'.
  $permissions['view field_commission'] = array(
    'name' => 'view field_commission',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_paid'.
  $permissions['view field_paid'] = array(
    'name' => 'view field_paid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_referred_by_level_1'.
  $permissions['view field_referred_by_level_1'] = array(
    'name' => 'view field_referred_by_level_1',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_referred_by_level_2'.
  $permissions['view field_referred_by_level_2'] = array(
    'name' => 'view field_referred_by_level_2',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own commerce_order entities'.
  $permissions['view own commerce_order entities'] = array(
    'name' => 'view own commerce_order entities',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view own commerce_order entities of bundle commerce_order'.
  $permissions['view own commerce_order entities of bundle commerce_order'] = array(
    'name' => 'view own commerce_order entities of bundle commerce_order',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view own field_commission'.
  $permissions['view own field_commission'] = array(
    'name' => 'view own field_commission',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_paid'.
  $permissions['view own field_paid'] = array(
    'name' => 'view own field_paid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_referred_by_level_1'.
  $permissions['view own field_referred_by_level_1'] = array(
    'name' => 'view own field_referred_by_level_1',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_referred_by_level_2'.
  $permissions['view own field_referred_by_level_2'] = array(
    'name' => 'view own field_referred_by_level_2',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
