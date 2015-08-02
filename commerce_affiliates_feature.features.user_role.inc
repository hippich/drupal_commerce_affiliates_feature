<?php
/**
 * @file
 * commerce_affiliates_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function commerce_affiliates_feature_user_default_roles() {
  $roles = array();

  // Exported role: affiliate.
  $roles['affiliate'] = array(
    'name' => 'affiliate',
  );

  return $roles;
}
