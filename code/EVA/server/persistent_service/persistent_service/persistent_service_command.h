#ifndef PSE_COMMAND_H_
#define PSE_COMMAND_H_

#include "persistent_service_def.h"
#include <persistent_service/db/db_manager.h>

PSE_NAMESPACE_BEGIN_DECL

/// �ֶ�����ȫ������;
NLMISC_COMMAND( close_service , " close service " , "" )
{
    if ( args.size() != 0 ) { return false; }
    DBManager.CloseService();
    log.displayNL("all execute db finish !");
    return true;
}

/// ������Ϸ����;
NLMISC_COMMAND( load_json , " load json info " , "" )
{
    if ( args.size() != 0 ) { return false; }
    JsonLoad.JsonLoadTable();
    log.displayNL("load json info finish !");
    return true;
}

/// ���ض����Ա�;
NLMISC_COMMAND( load_i18n , " load i18n info " , "" )
{
    if ( args.size() != 0 ) { return false; }
    CI18N::load( IService::getInstance()->ConfigFile.getVar("Language").asString() );
    log.displayNL("load i18n info finish !");
    return true;
}

PSE_NAMESPACE_END_DECL

#endif//PSE_COMMAND_H_