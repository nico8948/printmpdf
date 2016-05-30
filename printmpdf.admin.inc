<?php

/**
 * @file
 * Contains the administrative functions of the PDF conversion module.
 *
 * This file is included by the PDF conversion module, and includes the
 * settings form.
 */

/**
 * Admin configure form control on page.
 */
function printmpdf_config() {
  if (printmpdf_library_exist() == TRUE) { //always TRUE, issues require once for mpdf.
    $form['pdf'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#title' => t('PDF Tool Option'),
    );
    $filename = config_get('printmpdf.settings','printmpdf_pdf_filename');
    $form['pdf']['printmpdf_pdf_filename'] = array(
      '#type' => 'textfield',
      '#title' => t('PDF Filename'),
      '#required' => TRUE,
      '#description' => t('Default filename : !default_filename will be used.', array('!default_filename' => printmpdf_PDF_DEFAULT_FILENAME)),
      '#default_value' => isset($filename) && $filename != NULL ? $filename : printmpdf_PDF_DEFAULT_FILENAME,
    );
    $form['pdf']['printmpdf_pdf_save_option'] = array(
      '#type' => 'radios',
      '#title' => t('Open PDF File in'),
      '#options' => array(t('Web Browser'), t('Save Dialog Box'), t('Save to Server')),
      '#default_value' => config_get('printmpdf.settings','printmpdf_pdf_save_option'),
      '#description' => t("Default's to Web Browser."),
    );

    // PDF document properties.
    $form['pdf']['property'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#title' => t('Document Properties'),
      '#description' => t('These properties can be seen when inspecting the document properties like in Adobe Reader.'),
    );
    $form['pdf']['property']['printmpdf_pdf_set_title'] = array(
      '#type' => 'textfield',
      '#size' => 35,
      '#title' => t('Title'),
      '#default_value' => config_get('printmpdf.settings','printmpdf_pdf_set_title'),
      '#description' => t('Set the title for the document. If not required, leave blank.'),
    );
    $form['pdf']['property']['printmpdf_pdf_set_author'] = array(
      '#type' => 'textfield',
      '#size' => 35,
      '#title' => t('Author'),
      '#default_value' => config_get('printmpdf.settings','printmpdf_pdf_set_author'),
      '#description' => t('Set the Author for the document. If not required, leave blank.'),
    );
    $form['pdf']['property']['printmpdf_pdf_set_subject'] = array(
      '#type' => 'textfield',
      '#size' => 35,
      '#title' => t('Subject'),
      '#default_value' => config_get('printmpdf.settings','printmpdf_pdf_set_subject'),
      '#description' => t('Set Subject of PDF. If not required, leave blank.'),
    );
    $form['pdf']['property']['printmpdf_pdf_set_creator'] = array(
      '#type' => 'textfield',
      '#size' => 35,
      '#title' => t('Creator'),
      '#default_value' => config_get('printmpdf.settings','printmpdf_pdf_set_creator'),
      '#description' => t('Set the document Creator. If not required, leave blank.'),
    );
    // PDF page settings.
    $form['pdf']['page_setting'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#title' => t('PDF Page Setting'),
      '#description' => t('<p>All margin values should be specified as LENGTH in millimetres.</p>'),
    );
    $form['pdf']['page_setting']['printmpdf_margin_top'] = array(
      '#type' => 'textfield',
      '#size' => 5,
      '#title' => t('Top Margin'),
      '#default_value' => config_get('printmpdf.settings','printmpdf_margin_top'),
    );
    $form['pdf']['page_setting']['printmpdf_margin_right'] = array(
      '#type' => 'textfield',
      '#size' => 5,
      '#title' => t('Right Margin'),
      '#default_value' => config_get('printmpdf.settings','printmpdf_margin_right'),
    );
    $form['pdf']['page_setting']['printmpdf_margin_bottom'] = array(
      '#type' => 'textfield',
      '#size' => 5,
      '#title' => t('Bottom Margin'),
      '#default_value' => config_get('printmpdf.settings','printmpdf_margin_bottom'),
    );
    $form['pdf']['page_setting']['printmpdf_margin_left'] = array(
      '#type' => 'textfield',
      '#size' => 5,
      '#title' => t('Left Margin'),
      '#default_value' => config_get('printmpdf.settings','printmpdf_margin_left'),
    );
    $form['pdf']['page_setting']['printmpdf_margin_header'] = array(
      '#type' => 'textfield',
      '#size' => 5,
      '#title' => t('Header Margin'),
      '#default_value' => config_get('printmpdf.settings','printmpdf_margin_header'),
    );
    $form['pdf']['page_setting']['printmpdf_margin_footer'] = array(
      '#type' => 'textfield',
      '#size' => 5,
      '#title' => t('Footer Margin'),
      '#default_value' => config_get('printmpdf.settings','printmpdf_margin_footer'),
    );
    $form['pdf']['page_setting']['printmpdf_pdf_font_size'] = array(
      '#type' => 'textfield',
      '#size' => 5,
      '#title' => t('Font Size'),
      '#default_value' => config_get('printmpdf.settings','printmpdf_pdf_font_size'),
    );
    $form['pdf']['page_setting']['printmpdf_pdf_default_font'] = array(
      '#type' => 'select',
      '#title' => t('Default Font Style'),
      '#options' => array('DejaVuSerif' => 'Serif', 'DejaVuSerifCondensed' => 'Serif Condensed', 'DejaVuSans' => 'Sans Serif', 'DejaVuSansCondensed' => 'Sans Serif Condensed', 'DejaVuSansMono' => 'Monospaced'),
      '#default_value' => config_get('printmpdf.settings','printmpdf_pdf_default_font'),
      '#description' => t('This style can be overridden in the stylesheet.'),
    ); 
    $form['pdf']['page_setting']['printmpdf_pdf_page_size'] = array(
      '#type' => 'select',
      '#title' => t('Page Size'),
      '#options' => array(
        '2A0' => '2A0', '4A0' => '4A0', 'A0' => 'A0', 'A1' => 'A1', 'A2' => 'A2', 'A3' => 'A3', 'A4' => 'A4',
        'A5' => 'A5', 'A6' => 'A6', 'A7' => 'A7', 'A8' => 'A8', 'A9' => 'A9', 'A10' => 'A10', 'B0' => 'B0', 'B1' => 'B1',
        'B2' => 'B2', 'B3' => 'B3', 'B4' => 'B4', 'B5' => 'B5', 'B6' => 'B6', 'B7' => 'B7', 'B8' => 'B8', 'B9' => 'B9',
        'B10' => 'B10', 'C0' => 'C0', 'C1' => 'C1', 'C2' => 'C2', 'C3' => 'C3', 'C4' => 'C4', 'C5' => 'C5', 'C6' => 'C6',
        'C7' => 'C7', 'C8' => 'C8', 'C9' => 'C9', 'C10' => 'C10', 'RA0' => 'RA0', 'RA1' => 'RA1', 'RA2' => 'RA2',
        'SRA0' => 'SRA0', 'SRA1' => 'SRA1', 'SRA2' => 'SRA2', 'Letter' => 'Letter', 'Legal' => 'Legal',
      ),
      '#default_value' => config_get('printmpdf.settings','printmpdf_pdf_page_size'),
    );
    $form['pdf']['page_setting']['printmpdf_dpi'] = array(
      '#type' => 'textfield',
      '#size' => 5,
      '#title' => t('Document DPI'),
      '#default_value' => config_get('printmpdf.settings','printmpdf_dpi'),
    );
    $form['pdf']['page_setting']['printmpdf_img_dpi'] = array(
      '#type' => 'textfield',
      '#size' => 5,
      '#title' => t('Image DPI'),
      '#default_value' => config_get('printmpdf.settings','printmpdf_img_dpi'),
    );

    // Watermark Text/ Image option.
    $form['pdf']['watermark'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#title' => t('PDF Watermark Option'),
    );
    $form['pdf']['watermark']['printmpdf_watermark_option'] = array(
      '#type' => 'radios',
      '#title' => t('Watermark Option'),
      '#options' => array('text' => t('Watermark Text'), 'image' => t('Watermark Image')),
      '#default_value' => config_get('printmpdf.settings','printmpdf_watermark_option'),
    );
    $form['pdf']['watermark']['printmpdf_watermark_opacity'] = array(
      '#type' => 'select',
      '#title' => t('Watermark Transparency'),
      '#options' => array('0.1' => '0.1', '0.2' => '0.2', '0.3' => '0.3', '0.4' => '0.4', '0.5' => '0.5', '0.6' => '0.6', '0.7' => '0.7', '0.8' => '0.8', '0.9' => '0.9', '1.0' => '1.0'),
      '#default_value' => config_get('printmpdf.settings','printmpdf_watermark_opacity'),
    );
    $form['pdf']['watermark']['printmpdf_pdf_watermark_text'] = array(
      '#type' => 'textfield',
      '#title' => t('Watermark Text'),
      '#default_value' => config_get('printmpdf.settings','printmpdf_pdf_watermark_text'),
      '#description' => t('Display diagonal text on every page of PDF. If not required, leave it blank.'),
      '#states' => array(
        'visible' => array(
          ':input[name="printmpdf_watermark_option"]' => array('checked' => TRUE),
        ),
      ),
    );
    $form['pdf']['watermark']['printmpdf_watermark_image'] = array(
      '#type' => 'managed_file',
      '#title' => t('Watermark Image'),
      '#default_value' => config_get('printmpdf.settings','printmpdf_watermark_image'),
      '#upload_location' => 'public://',
      '#upload_validators' => array(
        'file_validate_extensions' => array('gif png jpg jpeg'),
        'file_validate_size' => array(MAX_FILE_SIZE * 1024 * 1024),
      ),
      '#states' => array(
        'visible' => array(
          ':input[name="printmpdf_watermark_option"]' => array('checked' => FALSE),
        ),
      ),
    );

    // Setting for PDF header.
    $form['pdf']['head_foot'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#title' => t('PDF Header & Footer Option'),
      '#description' => t('use {PAGENO} for page numbering or {DATE j-m-Y} for current date.'),
    );
    $form['pdf']['head_foot']['printmpdf_pdf_header'] = array(
      '#type' => 'textarea',
      '#title' => t('Header content'),
      '#description' => t('Use a valid HTML code to write a custom header content. Example:') . ' &#60;div&#62;&#60;img src="http://www.example.com/sites/default/files/company_logo.png" width="300px" height="50px" &#62;&#60;/div&#62; &#60;hr /&#62;',
      '#default_value' => config_get('printmpdf.settings','printmpdf_pdf_header'),
    );

    // Setting for PDF footer.
    $form['pdf']['head_foot']['printmpdf_pdf_footer'] = array(
      '#type' => 'textarea',
      '#title' => t('Footer content'),
      '#description' => t('Use a valid HTML code to write a custom footer content. Example:') . ' &#60;hr /&#62; &#60;div style="color:#f00; text-align:center;" &#62; &#60;strong&#62;Your Company&#60;/strong&#62;, web: &#60;a href="http://example.com"&#62;www.example.com&#60;/a&#62;, email : contact@example.com&#60;/div&#62;',
      '#default_value' => config_get('printmpdf.settings','printmpdf_pdf_footer'),
    );

    // Setting password to PDF, if entered.
    $form['pdf']['permission'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#title' => t('PDF Password Protection'),
    );
    $pwd = config_get('printmpdf.settings','printmpdf_pdf_password');
    if (isset($pwd) && $pwd != NULL) {
      $form['pdf']['permission']['msg'] = array(
        '#type' => 'markup',
        '#markup' => t('<p>Password : ******** is already set.</p>'),
      );
      $form['pdf']['permission']['remove_pwd'] = array(
        '#type' => 'checkbox',
        '#title' => t('Remove Password'),
      );
    }
    else {
      $form['pdf']['permission']['printmpdf_pdf_password'] = array(
        '#type' => 'password_confirm',
        '#description' => t('If password is not required, leave blank. Do not use space in starting and ending of password.'),
      );
    }
    // Setting Style Sheets to PDF.
    $form['pdf']['style'] = array(
      '#type' => 'fieldset',
      '#title' => t('Custom Style Sheets for PDF'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#description' => t('If not required, leave blank.'),
    );
    $form['pdf']['style']['printmpdf_pdf_css_file'] = array(
      '#type' => 'textfield',
      '#description' => t('Enter your name of css file, Example: style.css. Place all stylesheets either in the same module directory, i.e. "!module_path/" or current theme folder. If the file is in a folder in module or theme directory, enter the name with  path to that folder, for example : "css/custom_style.css".', array('!module_path' => backdrop_get_path('module', 'printmpdf'))),
      '#default_value' => config_get('printmpdf.settings','printmpdf_pdf_css_file'),
    );

    // Setting PDF permissions.
    $form['pdf']['permissions'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#title' => t('Content Type Permissions'),
    );
    $form['pdf']['permissions']['printmpdf_type_' . $type_name] = array(
      '#markup' => '<strong>' . t('Enable PDF generation for the following node types') . '</strong>',
    );
    $node_types = node_type_get_names();
    foreach ($node_types as $type_name => $node_type_name ) {
      $form['pdf']['permissions']['printmpdf_type_' . $type_name] = array(
        '#type' => 'checkbox',
        '#title' => $node_type_name,
        '#default_value' => config_get('printmpdf.settings','printmpdf_type_' . $type_name) != NULL ? 1 : 0,
      );
    }

   // return system_settings_form($form); alt ersetzt durch
    return printmpdf_settings_form($form);  //Kienitz
   
  }
  return $form;
}
/**
*  replaces system_settings_form($form) function - Kienitz
**/
function printmpdf_settings_form($form) {
  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Save configuration'));

  if (!empty($_POST) && form_get_errors()) {
    backdrop_set_message(t('The settings have not been saved because of the errors.'), 'error');
  }
  $form['#submit'][] = 'printmpdf_settings_form_submit';
  if (!isset($form['#theme'])) {
    $form['#theme'] = 'system_settings_form'; // use #theme of original function
  }
  return $form;
}

function printmpdf_settings_form_submit($form, &$form_state) {
  form_state_values_clean($form_state);

  foreach ($form_state['values'] as $key => $value) {
    if (is_array($value) && isset($form_state['values']['array_filter'])) {
      $value = array_keys(array_filter($value));
    }
    config_set('printmpdf.settings', $key, $value);
  }
  backdrop_set_message(t('The configuration options have been saved.'));
}

/**
 * Configuration form Validation check.
 */
function printmpdf_config_validate($form, $form_state) {

  // Checking mPDF library existence, always TRUE, issues require once for mpdf.
  if (printmpdf_library_exist() == TRUE) {
    if (isset($form_state['values']['remove_pwd'])) {
      if ($form_state['values']['remove_pwd'] == '1') {
        config_set('printmpdf.settings','printmpdf_pdf_password', NULL);
      }
    }
    if (!(is_numeric($form_state['values']['printmpdf_pdf_font_size']) && $form_state['values']['printmpdf_pdf_font_size'] > 1)) {
      form_set_error('font_size', t('Font size should be numeric and greater than 1.'));
    }
    if (!(is_numeric($form_state['values']['printmpdf_margin_top']) && $form_state['values']['printmpdf_margin_top'] >= 0)) {
      form_set_error('printmpdf_margin_top', t('PDF top margin should be numeric and greater than -1.'));
    }
    if (!(is_numeric($form_state['values']['printmpdf_margin_right']) && $form_state['values']['printmpdf_margin_right'] >= 0)) {
      form_set_error('printmpdf_margin_right', t('PDF right margin should be numeric and greater than -1.'));
    }
    if (!(is_numeric($form_state['values']['printmpdf_margin_bottom']) && $form_state['values']['printmpdf_margin_bottom'] >= 0)) {
      form_set_error('printmpdf_margin_bottom', t('PDF bottom margin should be numeric and greater than -1.'));
    }
    if (!(is_numeric($form_state['values']['printmpdf_margin_left']) && $form_state['values']['printmpdf_margin_left'] >= 0)) {
      form_set_error('printmpdf_margin_left', t('PDF left margin should be numeric and greater than -1.'));
    }
    if (!(is_numeric($form_state['values']['printmpdf_margin_header']) && $form_state['values']['printmpdf_margin_header'] >= 0)) {
      form_set_error('printmpdf_margin_header', t('PDF header margin should be numeric and greater than -1.'));
    }
    if (!(is_numeric($form_state['values']['printmpdf_margin_footer']) && $form_state['values']['printmpdf_margin_footer'] >= 0)) {
      form_set_error('printmpdf_margin_footer', t('PDF footer margin should be numeric and greater than -1.'));
    }    
    if (!(is_numeric($form_state['values']['printmpdf_dpi']) && $form_state['values']['printmpdf_dpi'] > 0)) {
      form_set_error('printmpdf_dpi', t('Document DPI should be numeric and greater than 0.'));
    }    
    if (!(is_numeric($form_state['values']['printmpdf_img_dpi']) && $form_state['values']['printmpdf_img_dpi'] > 0)) {
      form_set_error('printmpdf_img_dpi', t('Image DPI should be numeric and greater than 0.'));
    }
  }
}
