/* *
 * @program: G722Codec
 *
 * @description: G722解码为pcm，编解码库取自webrtc源码
 *
 * @author: chenxiang
 *
 * @create: 2018-10-21 16:30
***/

#ifndef G722CODEC_G722DECODE_H
#define G722CODEC_G722DECODE_H

#include "../Public/Type.h"
#include "G722/g722_interface.h"

class G722Decode
{
public:
    G722Decode();

    virtual ~G722Decode();

public:
    bool Init();

    /*
     * @paramIn      pSrcBuf          待解码的G722数据，16k采样，其他规格需要再G722文件夹源码中设置
     *               nSrcSize         待解码G722数据大小(单位：字节)
     *
     * @paramOut     pDstBuf          解码后PCM数据，建议长度不小于4倍nSrcSize
     *
     * @return       解码出的pcm数据长度(单位：字节)
     */
    int Decode(const UInt8* pSrcBuf, const int nSrcSize, UInt8 * pDstBuf);

private:
    G722DecInst*                      m_pG722Decode = nullptr;
};


#endif //G722CODEC_G722DECODE_H
