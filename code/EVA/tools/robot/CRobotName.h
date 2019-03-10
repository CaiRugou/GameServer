#ifndef CRandomName_h__
#define CRandomName_h__
#include <string>
#include <vector>
#include <nel/misc/random.h>

class CRobotName
{
public:
    CRobotName( void );
   ~CRobotName( void );

    // ���������ļ�;
    void LoadRandomName( void );

    // �������;
    std::string GetRandomName( void );

    static CRobotName* GetInstance( void )
    {
        static CRobotName _inst;
        return ( &_inst );
    }

private:
    NLMISC::CRandom            m_Random;
    std::vector< std::string > m_Surname;
    std::vector< std::string > m_Name;

    CRobotName( const CRobotName& rhs );
    CRobotName & operator = ( const CRobotName& rhs );
};

#define RobotName CRobotName::GetInstance()

#endif // CRandomName_h__