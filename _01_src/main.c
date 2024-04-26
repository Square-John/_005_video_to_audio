#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FFmpeg_CMD "ffmpeg"

int main(int argc, char *argv[]) {
    // 检查参数
    if (argc != 3) {
        printf("用法：%s <输入视频文件> <输出音频文件>\n", argv[0]);
        return 1;
    }

    // 定义输入和输出文件
    char *input_file = argv[1];
    char *output_file = argv[2];

    // 构造 FFmpeg 命令
    char cmd[1024];
    snprintf(cmd, sizeof(cmd), "%s -i %s -ab 160k -ac 2 -ar 44100 -vn %s",
             FFmpeg_CMD, input_file, output_file);

    // 运行 FFmpeg 命令
    system(cmd);

    return 0;
}