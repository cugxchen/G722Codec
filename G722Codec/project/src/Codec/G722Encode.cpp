/* *
 * @program: G722Codec
 *
 * @description: ${description}
 *
 * @author: chenxiang
 *
 * @create: 2018-10-21 16:30
***/

#include "G722Encode.h"
#include <iostream>

using namespace std;

G722Encode::G722Encode()
{
}

G722Encode::~G722Encode()
{

}


bool G722Encode::Init()
{
    bool bRet = false;

    do
    {
        if (WebRtcG722_CreateEncoder(&m_pG722Encode) != 0)
        {
            cout<<"WebRtcG722_CreateEncoder failed"<<endl;
            break;
        }
        if (WebRtcG722_EncoderInit(m_pG722Encode) != 0)
        {
            cout<<"WebRtcG722_EncoderInit failed"<<endl;
            break;
        }
    }while (0);

    return bRet;
}

int G722Encode::Encode(const UInt8 *pSrcBuf, const int nSrcSize, UInt8 *pDstBuf)
{
    Int16 *const pSrc16BitBuff = (Int16 *)pSrcBuf;
    Int32 nSrc16BitLen = nSrcSize/ sizeof(Int16);
    Int32 nEncode = WebRtcG722_Encode(m_pG722Encode, pSrc16BitBuff, nSrc16BitLen, pDstBuf);
    return nEncode;
}
