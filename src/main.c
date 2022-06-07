/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/07 12:29:10 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



#include <stdio.h>
void	printer(t_stack *stack)
{
	while (stack->next)
	{
		printf("Current value: %d\n", stack->value);
		stack = stack->next;
	}
	printf("Current value: %d\n", stack->value);	
}


int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc < 2)
		exit(1);
	env = ft_calloc(1, sizeof(t_env));
	if ((!env))
		clean_and_exit("Error", env, 1);
	(void)argv;
	parse_input(argv, env); // 1 memory leak
	//check_input(env);
	//sort_stack(env);
	//printer(env->stack_a);
	//clean_nodes(&env->stack_a);
	//clean_nodes(&env->stack_b);
	//free(env);
	system("leaks push_swap");
	return (0);
}



/*
500 test

#linux
make re && ./push_swap 100 403 800 -610 324 -783 212 -182 -36 777 545 329 -858 -759 -193 -672 -734 76 -489 -84 871 698 946 -184 672 -183 268 537 71 -40 -52 -72 596 434 -832 476 380 15 -460 781 -631 744 245 -46 396 -124 686 120 -654 818 -4 -303 247 397 217 170 65 599 240 -555 797 205 -581 -324 298 -520 143 90 135 -114 -462 74 229 -50 970 920 -315 695 -11 68 490 562 -588 426 566 213 906 761 -819 -756 12 869 -384 -144 -838 -326 428 847 -190 682 713 903 -594 -459 -441 244 837 885 -455 547 -739 -521 -991 -841 -399 -817 312 -885 346 -194 -26 -450 -657 -599 109 801 -449 805 -168 -980 -586 -200 785 -897 976 -18 481 981 -683 621 -612 29 -155 -285 -435 -836 881 -902 754 355 252 -653 224 -502 989 -62 -328 509 -453 -619 675 -73 536 574 -231 788 215 -60 -288 936 910 -938 880 980 132 -30 -772 145 -443 -640 -218 -551 -447 -511 21 -166 -602 466 -376 -537 -678 -228 -414 582 953 824 -142 -566 -854 -697 512 -428 -370 -623 484 -335 -780 408 705 493 286 -630 644 95 10 118 931 -584 -147 -58 -313 -526 80 528 -883 718 -775 500 861 -70 542 -940 -618 955 -561 -426 531 -268 38 290 101 448 313 549 -571 -108 731 -867 -968 -105 -55 -601 -364 222 94 -103 437 148 -332 -297 962 -486 820 -209 -849 13 743 6 -585 790 -774 -172 478 -307 273 334 -554 572 129 677 -390 739 -283 14 -974 630 942 -293 190 -321 663 87 237 -236 297 295 242 -259 -238 227 -252 133 855 -790 -606 287 300 966 -220 -131 901 -713 -934 -96 559 887 -162 -952 -650 905 -347 -143 -870 264 570 -371 -53 78 -550 487 -377 968 -442 -433 405 385 681 -879 -648 -668 733 86 951 -128 -148 935 154 676 -712 393 -563 -720 127 192 200 179 -529 238 -13 391 925 444 429 -353 137 -230 -221 -843 796 -896 -557 138 991 -987 -567 -10 -100 -175 186 835 40 614 -436 560 -577 -248 496 769 -57 580 43 3 694 -692 283 670 -150 144 -178 301 498 -724 -382 364 343 -463 -660 -928 -935 -369 573 250 -134 -255 128 -498 659 399 -919 -47 -905 -976 -904 -805 420 -758 712 -690 386 -765 116 -110 -21 62 216 771 -65 730 -796 -258 -139 -430 44 -751 639 -357 -506 520 322 -487 497 421 -12 738 943 799 -336 -530 -245 -910 185 717 -417 -757 700 414 891 342 926 894 415 -298 348 -821 -280 305 -208 477 533 857 -546 -346 914 -385 -253 -188 188 37 474 -117 -846 -325 940 -950 854 -605 -939 -101 341 -869 | ./checker_linux 100 403 800 -610 324 -783 212 -182 -36 777 545 329 -858 -759 -193 -672 -734 76 -489 -84 871 698 946 -184 672 -183 268 537 71 -40 -52 -72 596 434 -832 476 380 15 -460 781 -631 744 245 -46 396 -124 686 120 -654 818 -4 -303 247 397 217 170 65 599 240 -555 797 205 -581 -324 298 -520 143 90 135 -114 -462 74 229 -50 970 920 -315 695 -11 68 490 562 -588 426 566 213 906 761 -819 -756 12 869 -384 -144 -838 -326 428 847 -190 682 713 903 -594 -459 -441 244 837 885 -455 547 -739 -521 -991 -841 -399 -817 312 -885 346 -194 -26 -450 -657 -599 109 801 -449 805 -168 -980 -586 -200 785 -897 976 -18 481 981 -683 621 -612 29 -155 -285 -435 -836 881 -902 754 355 252 -653 224 -502 989 -62 -328 509 -453 -619 675 -73 536 574 -231 788 215 -60 -288 936 910 -938 880 980 132 -30 -772 145 -443 -640 -218 -551 -447 -511 21 -166 -602 466 -376 -537 -678 -228 -414 582 953 824 -142 -566 -854 -697 512 -428 -370 -623 484 -335 -780 408 705 493 286 -630 644 95 10 118 931 -584 -147 -58 -313 -526 80 528 -883 718 -775 500 861 -70 542 -940 -618 955 -561 -426 531 -268 38 290 101 448 313 549 -571 -108 731 -867 -968 -105 -55 -601 -364 222 94 -103 437 148 -332 -297 962 -486 820 -209 -849 13 743 6 -585 790 -774 -172 478 -307 273 334 -554 572 129 677 -390 739 -283 14 -974 630 942 -293 190 -321 663 87 237 -236 297 295 242 -259 -238 227 -252 133 855 -790 -606 287 300 966 -220 -131 901 -713 -934 -96 559 887 -162 -952 -650 905 -347 -143 -870 264 570 -371 -53 78 -550 487 -377 968 -442 -433 405 385 681 -879 -648 -668 733 86 951 -128 -148 935 154 676 -712 393 -563 -720 127 192 200 179 -529 238 -13 391 925 444 429 -353 137 -230 -221 -843 796 -896 -557 138 991 -987 -567 -10 -100 -175 186 835 40 614 -436 560 -577 -248 496 769 -57 580 43 3 694 -692 283 670 -150 144 -178 301 498 -724 -382 364 343 -463 -660 -928 -935 -369 573 250 -134 -255 128 -498 659 399 -919 -47 -905 -976 -904 -805 420 -758 712 -690 386 -765 116 -110 -21 62 216 771 -65 730 -796 -258 -139 -430 44 -751 639 -357 -506 520 322 -487 497 421 -12 738 943 799 -336 -530 -245 -910 185 717 -417 -757 700 414 891 342 926 894 415 -298 348 -821 -280 305 -208 477 533 857 -546 -346 914 -385 -253 -188 188 37 474 -117 -846 -325 940 -950 854 -605 -939 -101 341 -869

#mac
make re && ./push_swap 100 403 800 -610 324 -783 212 -182 -36 777 545 329 -858 -759 -193 -672 -734 76 -489 -84 871 698 946 -184 672 -183 268 537 71 -40 -52 -72 596 434 -832 476 380 15 -460 781 -631 744 245 -46 396 -124 686 120 -654 818 -4 -303 247 397 217 170 65 599 240 -555 797 205 -581 -324 298 -520 143 90 135 -114 -462 74 229 -50 970 920 -315 695 -11 68 490 562 -588 426 566 213 906 761 -819 -756 12 869 -384 -144 -838 -326 428 847 -190 682 713 903 -594 -459 -441 244 837 885 -455 547 -739 -521 -991 -841 -399 -817 312 -885 346 -194 -26 -450 -657 -599 109 801 -449 805 -168 -980 -586 -200 785 -897 976 -18 481 981 -683 621 -612 29 -155 -285 -435 -836 881 -902 754 355 252 -653 224 -502 989 -62 -328 509 -453 -619 675 -73 536 574 -231 788 215 -60 -288 936 910 -938 880 980 132 -30 -772 145 -443 -640 -218 -551 -447 -511 21 -166 -602 466 -376 -537 -678 -228 -414 582 953 824 -142 -566 -854 -697 512 -428 -370 -623 484 -335 -780 408 705 493 286 -630 644 95 10 118 931 -584 -147 -58 -313 -526 80 528 -883 718 -775 500 861 -70 542 -940 -618 955 -561 -426 531 -268 38 290 101 448 313 549 -571 -108 731 -867 -968 -105 -55 -601 -364 222 94 -103 437 148 -332 -297 962 -486 820 -209 -849 13 743 6 -585 790 -774 -172 478 -307 273 334 -554 572 129 677 -390 739 -283 14 -974 630 942 -293 190 -321 663 87 237 -236 297 295 242 -259 -238 227 -252 133 855 -790 -606 287 300 966 -220 -131 901 -713 -934 -96 559 887 -162 -952 -650 905 -347 -143 -870 264 570 -371 -53 78 -550 487 -377 968 -442 -433 405 385 681 -879 -648 -668 733 86 951 -128 -148 935 154 676 -712 393 -563 -720 127 192 200 179 -529 238 -13 391 925 444 429 -353 137 -230 -221 -843 796 -896 -557 138 991 -987 -567 -10 -100 -175 186 835 40 614 -436 560 -577 -248 496 769 -57 580 43 3 694 -692 283 670 -150 144 -178 301 498 -724 -382 364 343 -463 -660 -928 -935 -369 573 250 -134 -255 128 -498 659 399 -919 -47 -905 -976 -904 -805 420 -758 712 -690 386 -765 116 -110 -21 62 216 771 -65 730 -796 -258 -139 -430 44 -751 639 -357 -506 520 322 -487 497 421 -12 738 943 799 -336 -530 -245 -910 185 717 -417 -757 700 414 891 342 926 894 415 -298 348 -821 -280 305 -208 477 533 857 -546 -346 914 -385 -253 -188 188 37 474 -117 -846 -325 940 -950 854 -605 -939 -101 341 -869 | ./checker_Mac 100 403 800 -610 324 -783 212 -182 -36 777 545 329 -858 -759 -193 -672 -734 76 -489 -84 871 698 946 -184 672 -183 268 537 71 -40 -52 -72 596 434 -832 476 380 15 -460 781 -631 744 245 -46 396 -124 686 120 -654 818 -4 -303 247 397 217 170 65 599 240 -555 797 205 -581 -324 298 -520 143 90 135 -114 -462 74 229 -50 970 920 -315 695 -11 68 490 562 -588 426 566 213 906 761 -819 -756 12 869 -384 -144 -838 -326 428 847 -190 682 713 903 -594 -459 -441 244 837 885 -455 547 -739 -521 -991 -841 -399 -817 312 -885 346 -194 -26 -450 -657 -599 109 801 -449 805 -168 -980 -586 -200 785 -897 976 -18 481 981 -683 621 -612 29 -155 -285 -435 -836 881 -902 754 355 252 -653 224 -502 989 -62 -328 509 -453 -619 675 -73 536 574 -231 788 215 -60 -288 936 910 -938 880 980 132 -30 -772 145 -443 -640 -218 -551 -447 -511 21 -166 -602 466 -376 -537 -678 -228 -414 582 953 824 -142 -566 -854 -697 512 -428 -370 -623 484 -335 -780 408 705 493 286 -630 644 95 10 118 931 -584 -147 -58 -313 -526 80 528 -883 718 -775 500 861 -70 542 -940 -618 955 -561 -426 531 -268 38 290 101 448 313 549 -571 -108 731 -867 -968 -105 -55 -601 -364 222 94 -103 437 148 -332 -297 962 -486 820 -209 -849 13 743 6 -585 790 -774 -172 478 -307 273 334 -554 572 129 677 -390 739 -283 14 -974 630 942 -293 190 -321 663 87 237 -236 297 295 242 -259 -238 227 -252 133 855 -790 -606 287 300 966 -220 -131 901 -713 -934 -96 559 887 -162 -952 -650 905 -347 -143 -870 264 570 -371 -53 78 -550 487 -377 968 -442 -433 405 385 681 -879 -648 -668 733 86 951 -128 -148 935 154 676 -712 393 -563 -720 127 192 200 179 -529 238 -13 391 925 444 429 -353 137 -230 -221 -843 796 -896 -557 138 991 -987 -567 -10 -100 -175 186 835 40 614 -436 560 -577 -248 496 769 -57 580 43 3 694 -692 283 670 -150 144 -178 301 498 -724 -382 364 343 -463 -660 -928 -935 -369 573 250 -134 -255 128 -498 659 399 -919 -47 -905 -976 -904 -805 420 -758 712 -690 386 -765 116 -110 -21 62 216 771 -65 730 -796 -258 -139 -430 44 -751 639 -357 -506 520 322 -487 497 421 -12 738 943 799 -336 -530 -245 -910 185 717 -417 -757 700 414 891 342 926 894 415 -298 348 -821 -280 305 -208 477 533 857 -546 -346 914 -385 -253 -188 188 37 474 -117 -846 -325 940 -950 854 -605 -939 -101 341 -869
make re && ./push_swap 100 403 800 -610 324 -783 212 -182 -36 777 545 329 -858 -759 -193 -672 -734 76 -489 -84 871 698 946 -184 672 -183 268 537 71 -40 -52 -72 596 434 -832 476 380 15 -460 781 -631 744 245 -46 396 -124 686 120 -654 818 -4 -303 247 397 217 170 65 599 240 -555 797 205 -581 -324 298 -520 143 90 135 -114 -462 74 229 -50 970 920 -315 695 -11 68 490 562 -588 426 566 213 906 761 -819 -756 12 869 -384 -144 -838 -326 428 847 -190 682 713 903 -594 -459 -441 244 837 885 -455 547 -739 -521 -991 -841 -399 -817 312 -885 346 -194 -26 -450 -657 -599 109 801 -449 805 -168 -980 -586 -200 785 -897 976 -18 481 981 -683 621 -612 29 -155 -285 -435 -836 881 -902 754 355 252 -653 224 -502 989 -62 -328 509 -453 -619 675 -73 536 574 -231 788 215 -60 -288 936 910 -938 880 980 132 -30 -772 145 -443 -640 -218 -551 -447 -511 21 -166 -602 466 -376 -537 -678 -228 -414 582 953 824 -142 -566 -854 -697 512 -428 -370 -623 484 -335 -780 408 705 493 286 -630 644 95 10 118 931 -584 -147 -58 -313 -526 80 528 -883 718 -775 500 861 -70 542 -940 -618 955 -561 -426 531 -268 38 290 101 448 313 549 -571 -108 731 -867 -968 -105 -55 -601 -364 222 94 -103 437 148 -332 -297 962 -486 820 -209 -849 13 743 6 -585 790 -774 -172 478 -307 273 334 -554 572 129 677 -390 739 -283 14 -974 630 942 -293 190 -321 663 87 237 -236 297 295 242 -259 -238 227 -252 133 855 -790 -606 287 300 966 -220 -131 901 -713 -934 -96 559 887 -162 -952 -650 905 -347 -143 -870 264 570 -371 -53 78 -550 487 -377 968 -442 -433 405 385 681 -879 -648 -668 733 86 951 -128 -148 935 154 676 -712 393 -563 -720 127 192 200 179 -529 238 -13 391 925 444 429 -353 137 -230 -221 -843 796 -896 -557 138 991 -987 -567 -10 -100 -175 186 835 40 614 -436 560 -577 -248 496 769 -57 580 43 3 694 -692 283 670 -150 144 -178 301 498 -724 -382 364 343 -463 -660 -928 -935 -369 573 250 -134 -255 128 -498 659 399 -919 -47 -905 -976 -904 -805 420 -758 712 -690 386 -765 116 -110 -21 62 216 771 -65 730 -796 -258 -139 -430 44 -751 639 -357 -506 520 322 -487 497 421 -12 738 943 799 -336 -530 -245 -910 185 717 -417 -757 700 414 891 342 926 894 415 -298 348 -821 -280 305 -208 477 533 857 -546 -346 914 -385 -253 -188 188 37 474 -117 -846 -325 940 -950 854 -605 -939 -101 341 -869
*/