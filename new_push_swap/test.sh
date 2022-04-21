#!/bin/bash
set -e
set -o pipefail
echo "500 Numbers"
ARG="1702 -18 28 794 -11 1928 546 1125 1453 -38 937 1527 1912 643 1318 844 137 1362 1802 910 -274 341 1554 1990 1911 -74 1195 1645 -212 256 1205 1259 1581 832 1416 1646 810 1116 1366 1930 -46 -150 1737 1467 1152 1838 1894 1120 592 -110 1344 17 652 1136 1270 943 1246 568 19 -342 671 1981 1504 1609 1837 554 1123 154 -15 162 -307 -98 1091 1235 124 1340 1834 1500 750 973 746 419 501 118 1263 -147 1879 1034 1220 1288 -267 295 -166 627 722 1219 292 230 494 1505 368 -75 42 -87 1122 1647 1181 156 509 406 1291 1024 -106 1206 -103 1203 847 181 479 388 480 1985 1088 923 22 1994 767 738 749 1164 -312 815 99 601 -159 1553 604 1692 92 1567 1277 -399 318 1649 1726 -284 -277 555 -386 914 1052 1096 1126 1061 -221 -153 833 450 -126 9 1787 -72 1008 877 1086 1639 -31 876 580 1583 1971 591 1954 165 1906 1591 -192 549 340 16 1931 1539 1175 441 889 913 757 783 1541 -48 77 502 1233 -379 226 1898 1868 -105 1831 53 216 487 257 974 -121 1729 1173 315 771 1033 1800 -10 867 1922 -138 248 264 -293 830 352 1982 1412 1130 117 135 1109 1201 1917 -131 1329 157 1669 -203 202 -380 -317 -330 1963 197 1176 525 25 472 -186 -331 326 1208 -58 1533 177 1369 1460 186 1414 823 1169 547 1662 1068 1476 361 1389 1807 -13 983 1213 1828 1297 -393 836 -327 1501 1390 545 151 351 1473 297 1212 187 1537 768 269 1622 1274 645 1520 1140 250 1698 -291 -35 1904 551 666 1588 548 499 689 1342 571 -169 1750 1613 71 -130 125 703 1681 207 -305 254 1325 -22 -78 -381 1655 -85 -79 1732 859 965 93 113 -148 1050 919 508 1079 -231 199 123 785 372 435 762 1734 -263 1442 967 -61 1226 939 1456 1359 1410 927 1373 -341 -70 1200 1028 1996 1211 1587 788 -353 128 1319 -226 719 1534 696 1060 -202 1513 1699 780 -56 288 1949 488 59 1959 1253 1869 433 1521 1886 1874 843 1948 299 966 1384 1794 188 748 -9 -193 166 -96 1115 1708 141 1102 1524 -139 -125 1393 1947 330 461 -24 1103 1589 629 930 100 1523 1555 1793 440 1650 1776 999 1615 -71 855 1413 1361 1718 1775 52 1832 1908 397 1026 -347 -146 870 201 1618 1603 1477 -172 1449 23 -195 1725 824 1516 291 866 1025 313 1784 1593 37 228 1634 1279 628 1481 1030 1408 -201 1966 -179 851 1446 1910 1723 962 1053 1378 -100 1051 1536 887 1056 404 1805 1295 1666 1294 1566 1179 1067 -143 -394 447 872 -122 -112 -164 1568 1672 -319 1840 1756 1483 1875 1087 175 -290 413 1651 -183 69"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1702 -18 28 794 -11 1928 546 1125 1453 -38 937 1527 1912 643 1318 844 137 1362 1802 910 -274 341 1554 1990 1911 -74 1195 1645 -212 256 1205 1259 1581 832 1416 1646 810 1116 1366 1930 -46 -150 1737 1467 1152 1838 1894 1120 592 -110 1344 17 652 1136 1270 943 1246 568 19 -342 671 1981 1504 1609 1837 554 1123 154 -15 162 -307 -98 1091 1235 124 1340 1834 1500 750 973 746 419 501 118 1263 -147 1879 1034 1220 1288 -267 295 -166 627 722 1219 292 230 494 1505 368 -75 42 -87 1122 1647 1181 156 509 406 1291 1024 -106 1206 -103 1203 847 181 479 388 480 1985 1088 923 22 1994 767 738 749 1164 -312 815 99 601 -159 1553 604 1692 92 1567 1277 -399 318 1649 1726 -284 -277 555 -386 914 1052 1096 1126 1061 -221 -153 833 450 -126 9 1787 -72 1008 877 1086 1639 -31 876 580 1583 1971 591 1954 165 1906 1591 -192 549 340 16 1931 1539 1175 441 889 913 757 783 1541 -48 77 502 1233 -379 226 1898 1868 -105 1831 53 216 487 257 974 -121 1729 1173 315 771 1033 1800 -10 867 1922 -138 248 264 -293 830 352 1982 1412 1130 117 135 1109 1201 1917 -131 1329 157 1669 -203 202 -380 -317 -330 1963 197 1176 525 25 472 -186 -331 326 1208 -58 1533 177 1369 1460 186 1414 823 1169 547 1662 1068 1476 361 1389 1807 -13 983 1213 1828 1297 -393 836 -327 1501 1390 545 151 351 1473 297 1212 187 1537 768 269 1622 1274 645 1520 1140 250 1698 -291 -35 1904 551 666 1588 548 499 689 1342 571 -169 1750 1613 71 -130 125 703 1681 207 -305 254 1325 -22 -78 -381 1655 -85 -79 1732 859 965 93 113 -148 1050 919 508 1079 -231 199 123 785 372 435 762 1734 -263 1442 967 -61 1226 939 1456 1359 1410 927 1373 -341 -70 1200 1028 1996 1211 1587 788 -353 128 1319 -226 719 1534 696 1060 -202 1513 1699 780 -56 288 1949 488 59 1959 1253 1869 433 1521 1886 1874 843 1948 299 966 1384 1794 188 748 -9 -193 166 -96 1115 1708 141 1102 1524 -139 -125 1393 1947 330 461 -24 1103 1589 629 930 100 1523 1555 1793 440 1650 1776 999 1615 -71 855 1413 1361 1718 1775 52 1832 1908 397 1026 -347 -146 870 201 1618 1603 1477 -172 1449 23 -195 1725 824 1516 291 866 1025 313 1784 1593 37 228 1634 1279 628 1481 1030 1408 -201 1966 -179 851 1446 1910 1723 962 1053 1378 -100 1051 1536 887 1056 404 1805 1295 1666 1294 1566 1179 1067 -143 -394 447 872 -122 -112 -164 1568 1672 -319 1840 1756 1483 1875 1087 175 -290 413 1651 -183 69"; ./push_swap $ARG | wc -l
echo "500 Numbers with non numeric"
ARG="1702 -18 28 794 -11 1928 546 1125 1453 -38 937 1527 1912 643 1318 844 137 1362 1802 910 -274 341 1554 1990 1911 -74 1195 1645 -212 256 1205 1259 1581 832 1416 1646 810 1116 1366 1930 -46 -150 1737 1467 1152 1838 1894 1120 592 -110 1344 17 652 1136 1270 943 1246 568 19 -342 671 1981 1504 1609 1837 554 1123 154 -15 162 -307 -98 1091 1235 124 1340 1834 1500 750 973 746 419 501 118 1263 -147 1879 1034 1220 1288 -267 295 -166 627 722 1219 292 230 494 1505 368 -75 42 -87 1122 1647 1181 156 509 406 1291 1024 -106 1206 -103 1203 847 181 479 388 480 1985 1088 923 22 1994 767 738 749 1164 -312 815 99 601 -159 1553 604 1692 92 1567 1277 -399 318 1649 1726 -284 -277 555 -386 914 1052 1096 1126 1061 -221 -153 833 450 -126 9 1787 -72 1008 877 1086 1639 -31 876 580 1583 1971 591 1954 165 1906 1591 -192 549 340 16 1931 1539 1175 441 889 913 757 783 1541 -48 77 502 1233 -379 226 1898 1868 -105 1831 53 216 487 257 974 -121 1729 1173 315 771 1033 1800 -10 867 1922 -138 248 264 -293 830 352 1982 1412 1130 117 135 1109 1201 1917 -131 1329 157 1669 -203 202 -380 -317 -330 1963 197 1176 525 25 472 -186 -331 326 1208 -58 1533 177 1369 1460 186 1414 823 1169 547 1662 1068 1476 361 1389 1807 -13 983 1213 1828 1297 -393 836 -327 1501 1390 545 151 351 1473 297 1212 187 1537 768 269 1622 1274 645 1520 1140 250 1698 -291 -35 1904 551 666 1588 548 499 689 1342 571 -169 1750 1613 71 -130 125 703 1681 207 -305 254 1325 -22 -78 -381 1655 -85 -79 1732 859 965 93 113 -148 1050 919 508 1079 -231 199 123 785 372 435 762 1734 -263 1442 967 -61 1226 939 1456 1359 1410 927 1373 -341 -70 1200 1028 1996 1211 1587 788 -353 128 1319 -226 719 1534 696 1060 -202 1513 1699 780 -56 288 1949 488 59 1959 1253 1869 433 1521 1886 1874 843 1948 299 966 1384 1794 188 748 -9 -193 166 -96 1115 1708 141 1102 1524 -139 -125 1393 1947 330 461 -24 1103 1589 629 930 100 1523 1555 1793 440 1650 1776 999 1615 -71 855 1413 1361 1718 1775 52 1832 1908 397 1026 -347 -146 870 201 1618 1603 1477 -172 1449 23 -195 1725 824 1516 291 866 1025 313 1784 1593 37 228 1634 1279 628 1481 1030 1408 -201 1966 -179 851 1446 1910 1723 962 1053 1378 -100 1051 1536 887 1056 404 1805 1295 1666 1294 1566 1179 1067 -143 -394 447 872 -122 -112 -164 1568 1672 -319 1a840 1756 1483 1875 1087 175 -290 413 1651 -183 69"; ./push_swap $ARG | ./checker_Mac $ARG
echo "500 Numbers with duplicates"
ARG="1702 -18 28 794 -11 1928 546 1125 1453 -38 937 1527 1912 643 1318 844 137 1362 1802 937 -274 341 1554 1990 1911 -74 1195 1645 -212 256 1205 1259 1581 832 1416 1646 810 1116 1366 1930 -46 -150 1737 1467 1152 1838 1894 1120 592 -110 1344 17 652 1136 1270 943 1246 568 19 -342 671 1981 1504 1609 1837 554 1123 154 -15 162 -307 -98 1091 1235 124 1340 1834 1500 750 973 746 419 501 118 1263 -147 1879 1034 1220 1288 -267 295 -166 627 722 1219 292 230 494 1505 368 -75 42 -87 1122 1647 1181 156 509 406 1291 1024 -106 1206 -103 1203 847 181 479 388 480 1985 1088 923 22 1994 767 738 749 1164 -312 815 99 601 -159 1553 604 1692 92 1567 1277 -399 318 1649 1726 -284 -277 555 -386 914 1052 1096 1126 1061 -221 -153 833 450 -126 9 1787 -72 1008 877 1086 1639 -31 876 580 1583 1971 591 1954 165 1906 1591 -192 549 340 16 1931 1539 1175 441 889 913 757 783 1541 -48 77 502 1233 -379 226 1898 1868 -105 1831 53 216 487 257 974 -121 1729 1173 315 771 1033 1800 -10 867 1922 -138 248 264 -293 830 352 1982 1412 1130 117 135 1109 1201 1917 -131 1329 157 1669 -203 202 -380 -317 -330 1963 197 1176 525 25 472 -186 -331 326 1208 -58 1533 177 1369 1460 186 1414 823 1169 547 1662 1068 1476 361 1389 1807 -13 983 1213 1828 1297 -393 836 -327 1501 1390 545 151 351 1473 297 1212 187 1537 768 269 1622 1274 645 1520 1140 250 1698 -291 -35 1904 551 666 1588 548 499 689 1342 571 -169 1750 1613 71 -130 125 703 1681 207 -305 254 1325 -22 -78 -381 1655 -85 -79 1732 859 965 93 113 -148 1050 919 508 1079 -231 199 123 785 372 435 762 1734 -263 1442 967 -61 1226 939 1456 1359 1410 927 1373 -341 -70 1200 1028 1996 1211 1587 788 -353 128 1319 -226 719 1534 696 1060 -202 1513 1699 780 -56 288 1949 488 59 1959 1253 1869 433 1521 1886 1874 843 1948 299 966 1384 1794 188 748 -9 -193 166 -96 1115 1708 141 1102 1524 -139 -125 1393 1947 330 461 -24 1103 1589 629 930 100 1523 1555 1793 440 1650 1776 999 1615 -71 855 1413 1361 1718 1775 52 1832 1908 397 1026 -347 -146 870 201 1618 1603 1477 -172 1449 23 -195 1725 824 1516 291 866 1025 313 1784 1593 37 228 1634 1279 628 1481 1030 1408 -201 1966 -179 851 1446 1910 1723 962 1053 1378 -100 1051 1536 887 1056 404 1805 1295 1666 1294 1566 1179 1067 -143 -394 447 872 -122 -112 -164 1568 1672 -319 1840 1756 1483 1875 1087 175 -290 413 1651 -183 69"; ./push_swap $ARG | ./checker_Mac $ARG
echo "100 Numbers"
ARG="1546 -357 1096 6 5 250 1866 1330 1654 1176 266 66 1971 48 1359 1355 108 654 419 452 1149 270 1371 261 1805 258 782 633 1776 1895 35 599 581 1440 531 1995 1120 99 -240 1511 86 1888 444 1339 835 -224 1736 -321 1024 1609 119 277 -151 792 1091 1415 1531 611 -167 482 1558 847 1207 1551 217 160 -120 492 327 1334 158 526 967 -369 845 1509 1524 1083 -149 -264 577 833 -282 -60 120 544 1025 646 -116 1763 386 280 385 1128 1989 768 1705 1240 -220 500 -145"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1546 -357 1096 6 5 250 1866 1330 1654 1176 266 66 1971 48 1359 1355 108 654 419 452 1149 270 1371 261 1805 258 782 633 1776 1895 35 599 581 1440 531 1995 1120 99 -240 1511 86 1888 444 1339 835 -224 1736 -321 1024 1609 119 277 -151 792 1091 1415 1531 611 -167 482 1558 847 1207 1551 217 160 -120 492 327 1334 158 526 967 -369 845 1509 1524 1083 -149 -264 577 833 -282 -60 120 544 1025 646 -116 1763 386 280 385 1128 1989 768 1705 1240 -220 500 -145"; ./push_swap $ARG | wc -l
echo "100 Numbers with non numeric"
ARG="1546 -357 1795 1096 250 1866 1330 1654 1176 266 66 1971 48 1359 1355 108 654 419 452 1149 270 1371 261 1805 258 782 633 1776 1895 35 599 581 1440 531 1995 1120 99 -240 1511 86 1888 444 1339 835 -224 1736 -321 1024 1609 119 277 -151 792 1091 1415 1531 611 -167 482 1558 847 1207 1551 217 160 -120 492 327 1334 158 526 967 -369 845 1509 1524 1083 -149 -264 577 833 -282 -60 120 544 1025 646 -116 1763 386 280 385 1128 1989 768 1705 1240 -220 50a0 -145"; ./push_swap $ARG | ./checker_Mac $ARG
echo "100 Numbers with duplicates"
ARG="1546 -357 1795 1096 250 1866 1330 1654 1176 266 66 1971 48 1359 1355 108 654 419 452 1149 270 1371 261 1805 258 782 633 1776 1895 35 599 581 1440 531 1995 1120 1995 -240 1511 86 1888 444 1339 835 -224 1736 -321 1024 1609 119 277 -151 792 1091 1415 1531 611 -167 482 1558 847 1207 1551 217 160 -120 492 327 1334 158 526 967 -369 845 1509 1524 1083 -149 -264 577 833 -282 -60 120 544 1025 646 -116 1763 386 280 385 1128 1989 768 1705 1240 -220 500 -145"; ./push_swap $ARG | ./checker_Mac $ARG
echo "20 Numbers"
ARG="948 -296 1388 480 1018 1592 956 1974 1358 178 1637 204 -249 1568 -88 240 623 871 -84 368"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="948 -296 1388 480 1018 1592 956 1974 1358 178 1637 204 -249 1568 -88 240 623 871 -84 368"; ./push_swap $ARG | wc -l
echo "20 Numbers with non numeric"
ARG="948 -296 1388 480 1018 1592 956 1974 1358 178 1637 204 -249 15s8 -88 240 623 871 -84 368"; ./push_swap $ARG | ./checker_Mac $ARG
echo "20 Numbers with duplicates"
ARG="948 -296 1388 480 1018 1592 -296 1974 1358 178 1637 204 -249 1568 -88 240 623 871 -84 368"; ./push_swap $ARG | ./checker_Mac $ARG
echo "20 Numbers with higher MAX Int"
ARG="948 -296 2147483648 480 1018 1592 -296 1974 1358 178 1637 204 -249 1568 -88 240 623 871 -84 368"; ./push_swap $ARG | ./checker_Mac $ARG
echo "20 Numbers with lower MIN Int"
ARG="948 -296 -2147483649 480 1018 1592 -296 1974 1358 178 1637 204 -249 1568 -88 240 623 871 -84 368"; ./push_swap $ARG | ./checker_Mac $ARG
echo "1 Number"
ARG="948"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="948"; ./push_swap $ARG | wc -l
echo "sorted Numbers 0-3"
ARG="0 1 2 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 1 2 3"; ./push_swap $ARG | wc -l
echo "sorted Numbers 0-9"
ARG="0 1 2 3 4 5 6 7 8 9"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 1 2 3 4 5 6 7 8 9"; ./push_swap $ARG | wc -l
echo "2 1 0"
ARG="2 1 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 0"; ./push_swap $ARG | wc -l
echo "1 5 2 4 3"
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 5 2 4 3"; ./push_swap $ARG | wc -l
echo "random 5 #1"
ARG="1205 995 1266 1162 1174"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1205 995 1266 1162 1174"; ./push_swap $ARG | wc -l
echo "random 5 #2"
ARG="1566 1168 -49 -187 866"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1566 1168 -49 -187 866"; ./push_swap $ARG | wc -l
echo "random 5 #3"
ARG="1500 998 433 983 -54"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1500 998 433 983 -54"; ./push_swap $ARG | wc -l
echo "random 5 #4"
ARG="1547 103 -380 1308 1847"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1547 103 -380 1308 1847"; ./push_swap $ARG | wc -l
echo "random 5 #5"
ARG="-246 -20 933 1878 1793"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="-246 -20 933 1878 1793"; ./push_swap $ARG | wc -l
