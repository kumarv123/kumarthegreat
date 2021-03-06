rm pa06

gcc -g -Wall -Wshadow answer06.c pa06.c -o pa06
echo "The corrupt case tests are:"

echo "width0"
./pa06 images/corrupt-testcases/width0.ee264 outputs/01.ppm

echo "bad-comment-length"
./pa06 images/corrupt-testcases/bad-comment-length.ee264 outputs/01.ppm

echo "big-width-height"
./pa06 images/corrupt-testcases/big-width-height.ee264 outputs/01.ppm

echo "check-magic-bits"
./pa06 images/corrupt-testcases/check-magic-bits.ee264 outputs/01.ppm

echo "comment-has-no-null-byte"
./pa06 images/corrupt-testcases/comment-has-no-null-byte.ee264 outputs/01.ppm

echo "height0"
./pa06 images/corrupt-testcases/height0.ee264 outputs/01.ppm

echo "height-wrong"
./pa06 images/corrupt-testcases/height-wrong.ee264 outputs/01.ppm

echo "incomplete-header"
./pa06 images/corrupt-testcases/incomplete-header.ee264 outputs/01.ppm

echo "incomplete-image"
./pa06 images/corrupt-testcases/incomplete-image.ee264 outputs/01.ppm



echo "The Correct test cases are:"


