/* *
 * @program: G722Codec
 *
 * @description: pcm编码为G722
 *
 * @author: chenxiang
 *
 * @create: 2018-10-21 16:30
***/

#ifndef G722CODEC_G722ENCODE_H
#define G722CODEC_G722ENCODE_H


#include "G722/g722_interface.h"
#include "../Public/Type.h"

class G722Encode
{
public:
    G722Encode();

    virtual ~G722Encode();

public:
    bool Init();

    /*
     * @paramIn      pSrcBuf          待编码的PCM数据(Audacity可播放)
     *               nSrcSize         待解码PCM数据大小(单位：字节)
     *
     * @paramOut     pDstBuf          编码后G722数据(可用vlc直接播放)，建议长度nSrcSize
     *
     * @return       解码出的pcm数据长度(单位：字节)
     */
    int Encode(const UInt8* pSrcBuf, const int nSrcSize, UInt8 * pDstBuf);


private:
    G722EncInst*                         m_pG722Encode = nullptr;
};


#endif //G722CODEC_G722ENCODE_H
