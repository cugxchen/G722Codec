#include <iostream>
#include <cassert>
#include "../Codec/G722Decode.h"
#include "../Codec/G722Encode.h"


using namespace std;

static const int PCM_BUF_LEN = 320;
static const int G722_BUF_LEN = 80;

int main()
{
    std::cout << "G722--->pcm--->G722    start" << std::endl;

    FILE *fpSrcG722 = fopen("./srcFile/src.g722", "rb");
    FILE *fpDesPcm = fopen("./dstFile/des.pcm", "wb");
    FILE *fpDesG722 = fopen("./dstFile/des.g722", "wb");
    assert((nullptr != fpSrcG722) && (nullptr != fpDesPcm) && (nullptr != fpDesG722));

    G722Decode decodeHandler;
    decodeHandler.Init();
    G722Encode encodeHandler;
    encodeHandler.Init();
    UInt8 pcmBuf[PCM_BUF_LEN] = {0};
    UInt8 g722Buf[G722_BUF_LEN] = {0};
    int nG722 = 0;
    int nPcm = 0;
    while ((nG722 = fread(g722Buf, sizeof(UInt8), G722_BUF_LEN, fpSrcG722)) > 0)
    {
        nPcm = decodeHandler.Decode(g722Buf, nG722, pcmBuf);//œ»Ω‚¬Î
        assert(nPcm <= PCM_BUF_LEN);
        if ((nPcm > 0) && (fpDesPcm != nullptr))
        {
            fwrite(pcmBuf, nPcm, 1, fpDesPcm);
        }

        nG722 = encodeHandler.Encode(pcmBuf, nPcm, g722Buf);//‘Ÿ±‡¬Î
        assert(nG722 <= G722_BUF_LEN);
        if ((nG722 > 0) && (fpDesG722 != nullptr))
        {
            fwrite(g722Buf, nG722, 1, fpDesG722);
        }
    }
    std::cout << "G722--->pcm--->G722    end" << std::endl;

    return 0;
}