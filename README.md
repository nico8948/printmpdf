Print using mPDF (printmpdf)
============================

Converts a HTML page to PDF using mPDF PHP Library.
It allows you to generate the following pdf documents of any node:

  `www.example.com/node/nid/pdf`

  where nid is the node id of content to render.


INSTALLATION
------------
- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules

Enable the Print Using mPDF module: Administration > Modules (admin/modules)

CONFIGURATION
-------------
- There are several settings that can be configured in the following places:

  Administration > Modules (admin/modules)
    Enable or disable the module. (default: disabled)

  Configuration > User accounts > Permissions (admin/config/people/permissions)
    Under Print using mPDF module.
    
  Configuration > User interface > Print using mPDF settings
  (admin/config/user-interface/mpdf)
    This is where all the module-specific configuration options can be set.

ICON and css
------------
- A pdf Icon (used for the button) and a ccs file are included with this module:
. file-icon.pdf-50px.png
. css/prinmpdf.css with the (example) class hideinpdf to hide elements in the PDF outptut

PRINTMPDF custom extra field with a pdf button
----------------------------------------------
- This field is added to the types activated (default: all) through the "Print using mPDF settings"
- Using the node display you can control the visibility, label and weight of the pdf button.
Don't forget to flush the cache after making changes! 

- It should be hidden in the 'Default' display setting so the Icon does not appear in the 
generated pdf output.

. The button is wrapped with  `<div class="printmpdfbutton">`

API
---
`printmpdf_api()`

This api function is available to content developers that prefer
to generate a pdf file of custom path. The function takes two 
parameters, first a rendered html content and an optional second 
parameter, name of the pdf file.

Calling the function like this:

  `printmpdf_api($html)`

will return the PDF file for the current html passed to it.

It is also possible to specify the function like this:

  `printmpdf_api("<html><body>Hello</body></html>", "mypdf")`

will return the PDF file with a "Hello" and file named "mypdf.pdf".

MPDF TOOL
--------
The printmpdf module requires the use of an external PDF generation tool.
The currently supported tools are mPDF. Please note that any errors/bugs in
those tools need to be reported and fixed by their maintainers. 
DO NOT report bugs in those tools in the PDF Using mPDF module's issue queue
at backdropcms.org

Default location /modules/printmpdf/mpdf/

MPDF support:
-------------
The mpdf Library  Vesrion 6.1 is distributed with the printmpdf.
MPDF's support for CSS is considerably worse than the other tools.
Unicode is supported (use of Unicode fonts result in HUGE files).  Page
header and footer are supported.

- The actual mpdf Version was downloaded mPDF from https://github.com/mpdf/mpdf
  
- Grant write access to the cache and images directories to your
  webserver user.
  
- Check https://github.com/mpdf/mpdf for further information.

MPDF LIMITATIONS and ISSUES
---------------------------
See https://mpdf.github.io/about-mpdf/limitations.html
and https://github.com/mpdf/mpdf/issues
  
Current Maintainer
------------------
- Jörg Kienitz (https://github.com/vtad)

Credits
-------
- Originally written for Drupal by
AbhijeetKalsi, gauravjeet_singh, sudanshu.singh, Bhupendra Singh, Yash Sharma
(http://www.osscube.com/)

License
-------
This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.
  
  
