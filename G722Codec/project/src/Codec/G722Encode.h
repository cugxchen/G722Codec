/* *
 * @program: G722Codec
 *
 * @description: pcm����ΪG722
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
     * @paramIn      pSrcBuf          �������PCM����(Audacity�ɲ���)
     *               nSrcSize         ������PCM���ݴ�С(��λ���ֽ�)
     *
     * @paramOut     pDstBuf          �����G722����(����vlcֱ�Ӳ���)�����鳤��nSrcSize
     *
     * @return       �������pcm���ݳ���(��λ���ֽ�)
     */
    int Encode(const UInt8* pSrcBuf, const int nSrcSize, UInt8 * pDstBuf);


private:
    G722EncInst*                         m_pG722Encode = nullptr;
};


#endif //G722CODEC_G722ENCODE_H
