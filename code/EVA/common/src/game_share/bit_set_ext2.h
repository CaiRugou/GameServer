#include <nel/misc/bit_set.h>
#include <nel/misc/sstring.h>


/*
    ռ2bit��Ϣ��ѹ���洢��ʽ��
    �洢�±�� 1 ��ʼ��
    ֵֻ��Ϊ   0 1 2 3��
*/

class CBitSetExt2
{
public:

    bool SetValue( uint32 idx, uint8 value )
    {
        if ( idx<MAX_INDEX && value < (1<<VALUE_USR_BIT) )
        {
            const uint bit_idx = idx << 1;

            if ( m_BitSet.size() <= bit_idx )
            {
                m_BitSet.resizeNoReset(bit_idx+VALUE_USR_BIT);
            }

            m_BitSet.clear(bit_idx);
            m_BitSet.clear(bit_idx+1);

            if ( value&1 )   {  m_BitSet.set( bit_idx );  }
            if ( value&2 )   {  m_BitSet.set( bit_idx+1 );  }

			return true;
        }
		return false;
    }

    uint32 GetValue( uint32 idx )
    {
        uint32 val = INVALID_VAL;

        if ( idx<Size() )
        {
            const uint bit_idx = idx << 1;

            val  = m_BitSet.get(bit_idx+1)<<1;
            val |= (uint32)m_BitSet.get(bit_idx);
        }

        return val;
    }

    void InitBitmap( std::string& array_str )
    {
        m_BitSet.resize(array_str.size()*8);

        if ( array_str.size()%sizeof(uint32) == 0 )
        {
            for ( uint i=0,j=0; i<array_str.size(); i+=sizeof(uint32) )
            {
                uint32 array_uint32 = *(uint32*)&array_str[i];
                m_BitSet.setUint( array_uint32, j++ );
            }
        }
        else
        {
            nlwarning( "array_str.size()%sizeof(uint32)!=0" );
        }
    }

    std::string& GetArrayStr()
    {
        const std::vector<uint32>& bit_vct = m_BitSet.getVector();
        m_ArrayStr.resize(bit_vct.size()*sizeof(uint32));

        for ( uint i=0; i<bit_vct.size(); ++i )
        {
            *(uint32*)&m_ArrayStr[i*sizeof(uint32)] = bit_vct[i];
        }
        return m_ArrayStr;
    }

    uint32 Size()
    {
        return m_BitSet.size()>>1;
    }

    NLMISC::CSString toString()
    {
        NLMISC::CSString s;
        for ( uint32 i=0; i!=Size(); ++i )
        {
            uint32 val = GetValue(i);

            s << "[" << i <<"]=";
            s << "" << val <<"    ";

            if ( i%5==0 )  {  s << "\n";  }
        }
        s << "\n";
        return s;
    }

    enum 
    {
        INVALID_VAL   = 0xff,
    };

private:

    enum EnumPrivate
    {
        VALUE_USR_BIT = 2,
        MAX_INDEX     = 1024,
    };

    NLMISC::CSString    m_ArrayStr;
    NLMISC::CBitSet     m_BitSet;
};
