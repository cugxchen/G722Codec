/* *
 * @program: G722Codec
 *
 * @description: G722����Ϊpcm��������ȡ��webrtcԴ��
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
     * @paramIn      pSrcBuf          �������G722���ݣ�16k���������������Ҫ��G722�ļ���Դ��������
     *               nSrcSize         ������G722���ݴ�С(��λ���ֽ�)
     *
     * @paramOut     pDstBuf          �����PCM���ݣ����鳤�Ȳ�С��4��nSrcSize
     *
     * @return       �������pcm���ݳ���(��λ���ֽ�)
     */
    int Decode(const UInt8* pSrcBuf, const int nSrcSize, UInt8 * pDstBuf);

private:
    G722DecInst*                      m_pG722Decode = nullptr;
};


#endif //G722CODEC_G722DECODE_H
