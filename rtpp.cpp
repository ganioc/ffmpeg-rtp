#include "main.h"

extern "C" {
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libavformat/avio.h>
    #include <libswscale/swscale.h>
}

using namespace  std;

int main(int argc, char** argv){
    cout <<"rtp parse" <<endl;
    cout << "avcodec_configuration : " << avcodec_configuration() << endl;

    // how to open the rtsp,

    // Open the initial context variables that are needed
    SwsContext* img_convert_ctx;
    AVFormatContext* format_ctx = avformat_alloc_context();
    AVCodecContext* codec_ctx = NULL;
    int video_stream_index;

    // how to check the SEI NAL unit

    return 0;
}