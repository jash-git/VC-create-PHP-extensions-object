#pragma once
extern zend_module_entry PHPTest_module_entry;          // PHPTest  �O�ӥܨҪ��u�{�W�r�A PHPTest_module_entry�Ophp�X�i�w���J�f�n��
#define phpext_PHPTest_ptr &PHPTest_module_entry

#ifdef PHP_WIN32
#define PHP_PHPTest_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#define PHP_PHPTest_API __attribute__ ((visibility("default")))
#else
#define PHP_PHPTest_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(PHPTest);
PHP_MSHUTDOWN_FUNCTION(PHPTest);
PHP_RINIT_FUNCTION(PHPTest);
PHP_RSHUTDOWN_FUNCTION(PHPTest);
PHP_MINFO_FUNCTION(PHPTest);

// PHP_FUNCTION  �Ω�w�q�n�ɥX��php�եΪ���ƦW�١A�o�اڭ̩w�q�F3�Ө�ơGinit_module�Atest_module, close_module
// PHP_FUNCTION  �u�Ψ��n����ƪ��W�١A�m���ƪ��ѼƱN�bcpp���w�q

PHP_FUNCTION(init_module);
PHP_FUNCTION(test_module);
PHP_FUNCTION(close_module);


/*
Declare any global variables you may need between the BEGIN
and END macros here:
ZEND_BEGIN_MODULE_GLOBALS(CSVirusAnalyse)
long  global_value;
char *global_string;
ZEND_END_MODULE_GLOBALS(CSVirusAnalyse)
*/

/* In every utility function you add that needs to use variables
in php_CSVirusAnalyse_globals, call TSRMLS_FETCH(); after declaring other
variables used by that function, or better yet, pass in TSRMLS_CC
after the last function argument and declare your utility function
with TSRMLS_DC after the last declared argument.  Always refer to
the globals in your function as CSGAVIRUSANALYSIS_G(variable).  You are
encouraged to rename these macros something shorter, see
examples in any other php module directory.
*/

#ifdef ZTS
#define PHPTEST_G(v) TSRMG(PHPTest_globals_id, zend_PHPTest_globals *, v)
#else
#define PHPTEST_G(v) (PHPTest_globals.v)
#endif