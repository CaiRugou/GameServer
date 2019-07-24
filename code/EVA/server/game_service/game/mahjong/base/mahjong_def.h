#ifndef GSE_MAHJONG_DEF_H_
#define GSE_MAHJONG_DEF_H_

#include <game_service/game_service/game_service_def.h>

GSE_NAMESPACE_BEGIN_DECL

#define MAX_COMMON_CARD                                 108     // ��ͨ������;
#define MAC_WIND_CARD                                   16      // ��������;
#define MASK_COLOR                                      0xF0    // ��ɫ����;
#define MASK_VALUE                                      0x0F    // ��ֵ����;
#define MAX_INDEX                                       42      // �������;
#define MAX_COMMON_VALUE                                0x41    // �����ͨ��;
#define MASK_AHOLD_INDEX                                100     // ץ������;

typedef uint32                                          WIKSTATE;
typedef uint8                                           CARD;       
// ��������;
typedef std::vector<CARD>                               TCard;

// ��ͨ��;
static CARD BaseCard[] = 
{
    0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,       //��;
    0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,       //��;
    0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,       //��;
    0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,       //��;
    0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,       //��;
    0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,       //��;
    0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,       //��;
    0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,       //��;
    0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,       //Ͳ;
    0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,       //Ͳ;
    0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,       //Ͳ;
    0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29        //Ͳ;
};

// ��������;
static CARD WindCard1[] =
{
    0x31,0x31,0x31,0x31,                                //��;
    0x32,0x32,0x32,0x32,                                //��;
    0x33,0x33,0x33,0x33,                                //��;
    0x34,0x34,0x34,0x34                                 //��;
};

// �з���;
static CARD WindCard2[] =
{
    0x35,0x35,0x35,0x35,                                //��;
    0x36,0x36,0x36,0x36,                                //��;
    0x37,0x37,0x37,0x37,                                //��;
};

// �齫���Ƽ���;
static CARD MJCardData[] =
{
    0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,       //��;
    0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,       //��;
    0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,       //Ͳ;
    0x31,0x32,0x33,0x34,0x35,0x36,0x37,                 //��;
};

// ģ��;
template< typename T >
size_t CountCard( const std::vector<T>& table , T value )
{
    return std::count( table.begin() , table.end() , value );
}

 // �Ƿ�������;
inline bool IsExistAllSidesCard( uint8 CardValue ) { return ( CardValue >= 0x31 && CardValue <= 0x34 ); }

// �Ƿ��з���;
inline bool IsExistAllZfbCard( uint8 CardValue )   { return ( CardValue >= 0x35 && CardValue <= 0x37 ); }

// �Ƿ���ͨ��;
inline bool IsExistCommonCard( uint8 CardValue )   { return ( CardValue >= 0x01 && CardValue <= 0x29 ); }

// �ж��Ƿ�ΪЧ��;
inline bool IsValidCard( sint32 CardValue )
{
    if ( CardValue <= 0 ) { return false; }
    uint8 Value = ( CardValue & MASK_VALUE );
    uint8 Color = ( CardValue & MASK_COLOR ) >> 4;
    bool CommonCard = ( ( Value >= 1 ) && ( Value <= 9 ) && ( Color <= 2 ) ); // ��ͨ��;
    bool WindCard   = ( ( Value >= 1 ) && ( Value <= 7 ) && ( Color == 3 ) ); // ��;
    if ( CommonCard || WindCard ) { return true; }
    return false;
}

// ����ת��ʵ����ֵ;
inline uint8 SwitchToCardData( sint32 CardIndex )
{
    if ( CardIndex < 0 ) { return 0; }
    if ( CardIndex >= MAX_INDEX ) { return 0; }
    return ( ( CardIndex/9) << 4) | (CardIndex%9+1);
}

// ��ת��ʵ������;
inline sint32 SwitchToCardIndex( uint8 CardValue )
{
    if ( !IsValidCard( CardValue ) ) { return -1; }
    uint8 Value = ( CardValue & MASK_VALUE );
    uint8 Color = ( CardValue & MASK_COLOR ) >> 4;
    return Color*9 + (Value-1);
}

// ɾ��״̬;
inline void DeleteState( uint32& State , uint32 DeleteState )
{
    uint32 Mask = 0;
    Mask = ( ~Mask )^DeleteState;
    State &= Mask;
}

GSE_NAMESPACE_END_DECL
#endif  //GSE_MAHJONG_DEF_H_