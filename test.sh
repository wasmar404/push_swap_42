#!/bin/bash
 gcc *.c utils/*.c stack_a/*.c stack_b/*.c -Wall -Wextra -Werror -o a
# ARG=7 6 5
# ARG="7 6 5"
# ARG="7" "6" "5"
# ARG="7" "6" "5" "4" "3" "2"
# ARG="7" "6" "5" "-7"
# ARG="7" "6" "5" "2" "-7"
# ARG=42
# ARG=3 2
# ARG=0 1 2 3
# ARG=0 1 2 3 4 5 6 7 8 9
# ARG=9 8 7 6 5 4 3 2 1 0
# ARG="35 52 67 91 86 863 59 34 18 212 6572 20 83";
# ARG="60 40 50 43 30 32 6 68 47 53 72 57 78 51 38 31 17 71 65 69 59 94 18 15 96 41 24 45 83 74 62 93 91 95 61 12 97 70 79 28 56 90 25 81 1 66 63 48 23 76 13 55 58 49 98 26 0 54 88 19 8 7 14 39 3 10 84 75 86 67 11 20 16 44 92 89 35 9 4 33 46 2 21 22 82 77 27 80 100 36 37 5 99 87 73 52 85 34 29 64 42"
# ARG="35 52 67 91 86 863 59 34 18 212 6572 20 83 6034 7835 8206 8688 7711 8628 8540 9293 2382 2042 1103 5601 8442 7549 6147 9734 5516 5772 2961 535 3992 8096 3618 9198 6094 2896 5260 8667 1809 2016 2763 1316 6748 6784 1375 7586 4175 8086 128 7895 5197 6382 5871 8597 1611 8629 761 1567 8080 6486 5392 3917 2162 5092 2977 7415 6954 3096 2772 6586 2373 7200 5724 6707 9396 7416 3944 3519 8722 136 107 7965 3743 2997 608 3739 8431 6696 8066 5064 239 8507 755 5006 9460 4447 7578 5094 8330 1909 8717 4529 8495 8369 8662 5962 7075 2036 6504 4524"
# ARG="3005 7991 8231 4296 4803 2642 6064 7069 5531		6429		852		2504		7870		2889		8622		7016		4513		3150		3248		5519		8118		8565		7054		9724 9712 8597 90 9983 720 4508 7404 6408 3905 7477 694 6543 5209 7152 4201 1256 3149 4284 2193 6922 1590 5278 4210 9327 613 5189 7426 1680 901 3452 6326 2715 3408 3099 2182 9125 346 704 8042 4245 9912 8302 6094 2815 1033 8768 8366 4981 4572 7391 8935 1716 6020 1481 796 5072 9341 3058 7156 1846 5037 2991 1059 7660 1463 5801 904 9595 6412 4156 9412 6372 7150 4302 4527 3537 5829 2924 4114 7119 6953 1688 1029 9060 5105 5854 1246 6060 1422 7268 9759 7381 5270 79 6475 9756 8592 6087 5143 4660 879 701 1354 9023 6258 1424 6684 1117 6270 4080 9546 3188 6891 7065 8563 821 2171 2470 7455 5753 5088 1295 2273 884 6849 9861 1917 9644 4662 6120 1075 6247 2189 2034 7447 3020 5992 142 5767 4676 5468 9373 699 3754 7185 5359 8478 628 6488 5267 9719 5369 9634 6206 4369 2828 4016 8700 6383 3689 392 6254 3412 864 9499 2680 4155 7375 7590 8584 9432 5786 5897 5512 2347 7066 8437 8364 9482 7211 121 4471 6608 5427 5554 5124 4193 4628 269 6077 6391 4995 3352 7926 5324 1271 5505 7413 6928 7374 8925 7055 2370 875 3894 1212 8813 3688 4517 5912 6943 8833 7304 4700 5029 5911 2795 9442 1085 9433 1247 5574 5555 8982 9233 9608 5203 722 3809 7671 6533 4762 5935 1487 3121 2072 7236 9031 4754 797 6812 5490 6984 9390 9543 4728 7030 220 3880 814 4669 9096 4875 2896 7858 1214 601 7732 9471 3183 1037 1710 5068 8748 5164 364 5849 5972 6252 546 2151 6605 3579 3607 5070 1781 336 2362 5160 8970 6728 4984 2503 2977 5440 6718 4858 8026 3626 5763 6460 8782 8371 2729 3430 1479 8675 7182 9867 9518 6108 9344 3351 6926 5458 3965 9491 1442 1433 513 270 9925 6896 4169 8012 8221 2809 5613 8344 9358 5479 9955 433 2225 4096 3384 7516 7655 4082 606 487 5987 6147 4818 9730 8984 1482 6441 7965 4720 1626 7651 2050 6955 3594 4952 9697 8280 6153 8650 158 144 1199 2574 9097 5066 3169 6717 8285 1770 1321 3681 3142 9793 6141 2274 6365 4045 1380 5238 5205 447 8152 5434 3 9967 8965 7323 2475 4899 2232 5871 6238 762 4036 9795 7442 938 6547 6815 7419 8806 5681 4248 2499 4213 778 1859 7172 7032 1030 7798 9429 6825 2613 7120 5667 1747 1285 2380 2052 2008 2396 3282 4093 5807 9115 1515 4690 5130 7348 9627 3133 2880 3289 7051 5293 1800 3960 1518 8571 4764 1926 1981 2912 5693 3163 3238 9505 559 5934 3396 9473 830 8362 1122 6428 8335 6578 5245 1649 9475 6410 5190 9478 6306 9052 5997 610 6043 3064 9156 5162 7437 8759 5737 6706 2352 8667 3744 4916 3545 1318 3941 3299 2607"
# ARG=c c c
# ARG=2 a 2
# ARG="2" "a" "2"
# ARG="b" "3" "2"
# ARG="9" "6" "5 4"
# ARG='Between 0 and 9 randomly sorted values chosen>'
# ./a.out $ARG
#  ./a.out $ARG | ./checker_linux $ARG
# ./a.out $ARG | ./checker_linux $ARG
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out $ARG
# ./a.out $ARG | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./checker $ARG
# ./a.out "60 40 50 43 30 32 6 68 47 53 72 57 78 51 38 31 17 71 65 69 59" "94 18 15 96 41 24 45 83 74 62 93 91 95 61 12 97 70 79 28 56 90 25 81 1 66 63 48 23 76" "13 55 58 49 98 26 0 54 88 19 8 7 14 39 3 10 84 75 86 67 11" "20 16 44 92 89" "35 9 4 33 46 2 21 22 82 77 27 80 100 36 37 5 99 87 73 52 85 34 29 64 42"
# ./a.out "60 40 50 43 30 32 6 68 47 53 72 57 78 51 38 31 17 71 65 69 59" "94 18 15 96 41 24 45 83 74 62 93 91 95 61 12 97 70 79 28 56 90 25 81 1 66 63 48 23 76" "13 55 58 49 98 26 0 54 88 19 8 7 14 39 3 10 84 75 86 67 11" "20 16 44 92 89" "35 9 4 33 46 2 21 22 82 77 27 80 100 36 37 5 99 87 73 52 85 34 29 64 42" | ./checker_linux
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out "60 40 50 43 30 32 6 68 47 53 72 57 78 51 38 31 17 71 65 69 59" "94 18 15 96 41 24 45 83 74 62 93 91 95 61 12 97 70 79 28 56 90 25 81 1 66 63 48 23 76" "13 55 58 49 98 26 0 54 88 19 8 7 14 39 3 10 84 75 86 67 11" "20 16 44 92 89" "35 9 4 33 46 2 21 22 82 77 27 80 100 36 37 5 99 87 73 52 85 34 29 64 42"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out "60 40 50 43 30 32 6 68 47 53 72 57 78 51 38 31 17 71 65 69 59" "94 18 15 96 41 24 45 83 74 62 93 91 95 61 12 97 70 79 28 56 90 25 81 1 66 63 48 23 76" "13 55 58 49 98 26 0 54 88 19 8 7 14 39 3 10 84 75 86 67 11" "20 16 44 92 89" "35 9 4 33 46 2 21 22 82 77 27 80 100 36 37 5 99 87 73 52 85 34 29 64 42" | ./checker_linux