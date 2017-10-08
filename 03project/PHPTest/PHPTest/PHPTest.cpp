// PHPTest.cpp : �w�q DLL ���ε{�����ץX�禡�C
//

#include "stdafx.h"

// �n���H�U�����w�q�ѨM�b�sĶ�L�{���|�o�͡Gerror C2466: ������t�`�q�j�p��0 ���Ʋժ����~�C
#ifdef PHP_WIN32  
#define _STATIC_ASSERT(expr) typedef char __static_assert_t[ (expr)?(expr):1 ]  
#else  
#define _STATIC_ASSERT(expr) typedef char __static_assert_t[ (expr) ]  
#endif  

// #include "XXXXX.h" �b�H�U�]�t�Y��󪺫e���]�t�n�Ψ쪺c++ ��stl���Y���A�Ϊ̧A�ۤv�g��C++���Y���C
#include <string>
using namespace std;

extern "C" {
#include "zend_config.w32.h"
#include "php.h"
#include "ext/standard/info.h"
#include "PHPTest.h"
}


// �n���F�X�i�w���ɥX��ƦC��
zend_function_entry PHPTest_functions[] = {
	PHP_FE(init_module, NULL)
	PHP_FE(test_module, NULL)
	PHP_FE(close_module, NULL)
	PHP_FE_END
};

zend_module_entry PHPTest_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"PHPTest",
	PHPTest_functions,
	PHP_MINIT(PHPTest),
	PHP_MSHUTDOWN(PHPTest),
	PHP_RINIT(PHPTest), /* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(PHPTest), /* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(PHPTest),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};


ZEND_GET_MODULE(PHPTest);

PHP_MINIT_FUNCTION(PHPTest)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(PHPTest)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}

PHP_RINIT_FUNCTION(PHPTest)
{
	return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(PHPTest)
{
	return SUCCESS;
}

PHP_MINFO_FUNCTION(PHPTest)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "PHPTest support", "enabled");
	php_info_print_table_end();


	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}

// �H�U�Ophp�ɥX��ƪ���{�A��pstring init_module(string content)
PHP_FUNCTION(init_module)
{
	char *content = NULL;   // 
	int argc = ZEND_NUM_ARGS();
	int content_len;
	// �o�y�ܫK�O�ɥX�ǤJ�Ѽ� 
	if (zend_parse_parameters(argc TSRMLS_CC, "s", &content, &content_len) == FAILURE)
		return;
	if (content)
	{
		//  �o�إu�O���F���աA������ǤJ�Ȫ�^�h�C
		string strRet = content;
		// ��^��
		RETURN_STRING((char*)strRet.c_str(), 1);
	}
	else
	{
		php_error(E_WARNING, "init_module: content is NULL");
	}
}

// �H�U�Oint test_module(string content)��ƪ���{
PHP_FUNCTION(test_module)
{
	char *content = NULL;
	int argc = ZEND_NUM_ARGS();
	int content_len;


	if (zend_parse_parameters(argc TSRMLS_CC, "s", &content, &content_len) == FAILURE)
		return;
	if (content)
	{
		int nRet = content_len;
		RETURN_LONG(nRet);
	}
	else
	{
		php_error(E_WARNING, "test_module: &content is NULL");
	}


}

// �H�U�O void close_module()��ƪ���{
PHP_FUNCTION(close_module)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	php_printf("close_module successfully\n");
}
