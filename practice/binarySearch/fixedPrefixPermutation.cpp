/**
 * to find maximum beauty for ai*aj for all j=1 to n for each i
 * b1 b2 beauties
 * b1<b2
 * b1 - 1 2 3 4 5 6 7 8 9 . . b1
 * b2 - 1 2 3 4 5 6 7 8 9 . . b1 . . . b2
 * b1*b2-b2[b1[]]- 1 2 3 4 5 6 7 8 9 . . .b1
 * b2*b1 - b1[b2[]]- 1 2 3 4 5 6 7 8 9 . . . b1
 * beauty = min(b1,b2);
 * b1 = b2 = t
 * b1*b2 - 1 2 3 4 5 6 7 8 9 . . . . t... ..k
 * b1*b2=t+x
 * b2[b1[t+x]]=t+x
 * for k = 1 to x
 * b2[p]=t+x
 * b1[t+x]=p
 * for t:t+x b1 should be the index array of b2
 * for 1 permutation
 * ans = max(min(bi,bj),t+x)
 * beauty of an ai.aj<=beauty(ai); if b[ai]!=b[aj]
 * so need to search for ak such that beauty of ai = beauty of aj
 * for a given ai may be i can use binary search to find the maximum beauty
 * no point in taking the permutaion with b(ai)<b(aj) and also b(ai)>b(aj) just find the upperbound of b(ai)
 * if no beauty found = b(ai) answer=upper_bound--;
 * # case2 beauty found =b(ai);
 * ai.aj=r
 * r[n]=aj[ai[n]]
 * now for r[n]=n
 * aj[ai[n]]=n=>aj should be an indexing set of ai till k
 * just bruteforcing the way through the solution gives tle
 * where[ai[n]]=n defined to state where the index of each permutaion is
 * k maximum value is till n
 * check(mid)= is mid a possible beauty
 * just have to check for the permutation with similar beauty
 *  if mid<b[ai] possible
 * aj[ai[mid]]=mid
 * now ai[mid]=x
 * check for those js where aj[x]=mid;
 * if k is the maximum beauty for ai.aj
 * ajaj[ai[n]]=n for n<=k
 * aj.ai  if ai[n]=x and [x]=n
 * let some y!=x points to x aj[y]=x
 *
 */