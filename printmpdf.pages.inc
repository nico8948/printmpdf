<?php

/**
 * @file
 * Contains all description to generate PDF document from raw HTML content.
 */

/**
 * Generate HTML of a given node.
 *
 * @return bool
 *   TRUE if PDF is successfully generated and FALSE if it isn't.
 */
function printmpdf_generate_pdf($node) {

  if (config_get('printmpdf.settings','printmpdf_type_' . $node->type) == 0 ) {
    backdrop_goto(urlencode('node') . '/' . $node->nid);
    return;
  }

  if (!node_access('view', $node)) {
    backdrop_set_message(t('You are not authorized to generate PDF for this page.'), 'warning');
    backdrop_goto(urlencode('node') . '/' . $node->nid);
    return;
  }
  if (empty($node)) {
    backdrop_get_messages('error');
    backdrop_set_message(t('PDF cannot be generated for this path.'), 'error');
    return;
  }

  // Checking mPDF library existence,  always TRUE, issues require once for mpdf.
  if (printmpdf_library_exist() == TRUE) {
    $printmpdf_pdf_filename = config_get('printmpdf.settings','printmpdf_pdf_filename');
    $printmpdf_pdf_filename = token_replace($printmpdf_pdf_filename, array('node' => $node));

    //$view = node_view($node);
    $view = node_view($node, 'PDF');
    $html = backdrop_render($view);

    _printmpdf_generator($html, $printmpdf_pdf_filename);
  }
}
