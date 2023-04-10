#include "main.h"

extern "C" {
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
}

using namespace  std;


int main(){
    cout <<"rtp parse" <<endl;
    cout << "avcodec_configuration : " << avcodec_configuration() << endl;
    return 0;
}