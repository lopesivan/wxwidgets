#!/bin/sh

set -xe

createImage() {
	W=$1
	H=$2
	newImage=$3
	COLOR=red
	COLOR=$4
	convert -depth 32 -size ${W}x${H} \
		xc:"$COLOR" -colorspace RGB \
		$newImage
}

# HD
# 16:9
W=500
H=500

output=image1.jpg
createImage $W $H ${output} '#436EEE'

output=image2.jpg
createImage $W $H ${output} '#FFBBFF'

output=image3.jpg
createImage $W $H ${output} '#93BFBF'
# ----------------------------------------------------------------------------
exit 0
