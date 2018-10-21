/* *
 * @program: G722Codec
 *
 * @description: ${description}
 *
 * @author: chenxiang
 *
 * @create: 2018-10-21 16:30
***/
#include <iostream>
#include "G722Decode.h"

using namespace std;


G722Decode::G722Decode()
{
}

G722Decode::~G722Decode()
{
    if (m_pG722Decode != nullptr)
    {
        WebRtcG722_FreeDecoder(m_pG722Decode);
    }
}


bool G722Decode::Init()
{
    bool bRet = false;
    do
    {
        if (WebRtcG722_CreateDecoder(&m_pG722Decode) != 0)
        {
            cout<<"WebRtcG722_CreateDecoder failed."<<endl;
            break;
        }
        if (WebRtcG722_DecoderInit(m_pG722Decode) != 0)
        {
            cout<<"WebRtcG722_DecoderInit failed."<<endl;
            break;
        }
        bRet = true;
    }while (0);

    return bRet;
}

int G722Decode::Decode(const UInt8 *pSrcBuf, const int nSrcSize, UInt8 *pDstBuf)
{
    int16_t speechType = 1;
    Int32 nDecode = WebRtcG722_Decode(m_pG722Decode, pSrcBuf, nSrcSize, (Int16*)pDstBuf, &speechType);
    return nDecode * sizeof(Int16);
}
