This is the code used in the paper below:

	D. J. C. Santiago, T. I. Ren, G. D. Cavalcanti, and T. I. Jyh, “Efficient 2×2 block-based connected 
	components labeling algorithms,” in International Conference on Image Processing (ICIP), 2015, pp. 
	4818 - 4822.

Abstract:

	This paper presents three new efficient 2×2 block-based algorithms for connected components labeling: 
	a two-scan which assigns provisional labels to blocks, a two-scan which assigns provisional labels to 
	pixels and a one-and-a-half-scan which assigns provisional labels to blocks. A new stripe image 
	representation is designed in order to perform the second pass only through the blocks containing some 
	foreground pixel. We also improved the existing 2×2 block-based algorithms by utilizing information of 
	a pixel during a transition in the mask, which allows checking of four neighbor pixels in the mask at 
	most. Thus, the average number of checking operations needed to inspect the neighbor pixels in the first 
	scan is reduced from 1.459 to 1.156, an improvement of 21%. We conducted experiments using synthetic and 
	real images to evaluate the performance of the proposed methods compared to the existing methods. The 
	proposed block-based one-and-a-half-scan algorithm presents the best performance in the real images 
	dataset, which is composed of 1290 documents. Our block-based two-scan algorithm which assigns 
	provisional labels to pixels showed to be the fastest in the synthetic dataset, especially in high 
	density images.


The code implements the following algorithms:

	[1] C. Grana, D. Borghesani, and R. Cucchiara, “Optimized block-based connected components labeling with 
	decision trees,” IEEE Transactions on Image Processing, vol. 19, n. 6, pp. 1596-1609, 2010.

	[2] L. He, Y. Chao, and K. Suzuki, “A new two-scan algorithm for labeling connected components in binary 
	images,” in Proceedings of the World Congress on Engineering, 2012, vol. 2, pp. 1141-1146.

	[3] D. J. C. Santiago, T. I. Ren, G. D. Cavalcanti, and T. I. Jyh, “Fast block-based algorithms for 
	connected components labeling,” in International Conference on Acoustics, Speech, and Signal Processing 
	(ICASSP), 2013, pp. 2084-2088.

	[4] D. J. C. Santiago, T. I. Ren, G. D. Cavalcanti, and T. I. Jyh, “Efficient 2×2 block-based connected 
	components labeling algorithms,” in International Conference on Image Processing (ICIP), 2015, pp. 
	4818 - 4822.

	[5] P. Sutheebanjard and W. Premchaiswadi, “Efficient scan mask techniques for connected components 
	labeling algorithm,” EURASIP Journal on Image and Video Processing, 2011:14.


Compilation:

	Netbeans and Visual Studio projects are included in the repository.
