牛客算法精讲第四节（C语言+VS2017）
=======================================
>markdown格式学习——[点击链接](http://guoyunsky.iteye.com/blog/1781885)<br />
>>[前讲?](#前讲)
>[第一题?](#第一题)
>[第二题?](#第二题)
>[第三题?](#第三题)
>[第四题?](#第四题)
#前讲
####题目：
>找一个数组的连续子数组的最大和。
```
typedef int ArrayElem;
ArrayElem maxer(ArrayElem a, ArrayElem b)
{
	return a > b ? a : b;
}

ArrayElem SubArraySumMax(ArrayElem *array, int length)
{
	if (array == NULL || length == 0)
		return 0;
	//max存放array子数组最大和,初始值为系统最小值
	//cur_max存放当前子数组的和
	ArrayElem max = -100;
	ArrayElem cur_max = 0;

	for (int i = 0; i != length; i++)
	{
		cur_max += array[i];
		//max保存目前所有子数组和中的最大值
		max=maxer(max, cur_max);
		//如果当前最大值为0那么后续的数组不需要在前半段加一个负数使自己的和变小
		//也就是重新寻找后面的子数组最大和
		if (cur_max < 0)
			cur_max = 0;
	}
	return max;
}
```
# 第一题
 > 给定一个矩阵matrix，其中的值有正、有负、有0，返回子矩阵的最大累加和。
例如，矩阵matrix为：
```
-90    48    78  
 64   -40    64  
-81    -7    66
```
其中，最大累加和的子矩阵为：
```
  48    78  
 -40    64  
  -7    66
```
所以返回累加和209。
### 解题思路：
将4*4的矩阵看作是4行，那么子矩阵就必须是
1、12、123、1234；
2、23、234;
3、34;
4
共（1+4）*4/2种情况，每种情况的列相加得到一个数组（长度为矩阵列数），此时子矩阵和最大问题转换为字数组和最大问题。
### 时间复杂度
>O(n^2\*m)，其中n是行数，m是列数；
如果n>>m，那么以m作为列会大大降低时间复杂度，即O(m^2\*n)；
```
ArrayElem SubMatrixSumMax(ArrayElem *array, int row_len, int col_len)
{
	if (array == NULL || row_len == 0 || col_len == 0)
		return 0;
	ArrayElem *s = (ArrayElem *)malloc(sizeof(ArrayElem)*col_len);
	int max=-10000;
	int cur_lin_max;
	for (int i = 0; i < row_len; i++)
	{
		memset(s, 0, col_len * sizeof(ArrayElem));
		for (int j = i; j < row_len; j++)
		{
			cur_lin_max = 0;
			for (int k = 0; k < col_len; k++)
			{
               //s里面存放的就是累加和，算出一个元素直接求子数组最大和
				*(s + k) += array[j*col_len+k];
				cur_lin_max += *(s + k);
				max=maxer(cur_lin_max, max);
				if (cur_lin_max < 0)
					cur_lin_max = 0;
			}
		}
	}
	free(s);
	return max;
}
```
# 第二题
>给定一个数组，每个位置的值代表一个高度。那么整个数组可以看成是一个直方图。如果把这个直方图当作容器的话，求这个容器能装多少水。
例如：
```
[3,1,2,4]
```
>代表第一个位置高度为3，第二个位置高度为1，第三个位置高度为2，第四个位置高度为4。

>所以[3,1,2,4]这个数组代表的容器可以装3格的水。
#### 解题思路
>思路一：
每个元素能留多少水由它右边最大值maxR和左边最大值maxL中的较小值miner决定，元素i盛水值为miner-array[i]。
实现方法：
正反遍历两次得到两个数组分别记录元素i处左边最大值和右边最大值；
最后遍历遍历一遍得到蓄水量总和。

>思路二：
设数组长度为n，两个指针a,b分别指向元素1和n-1，那么1处的蓄水量由1左边和n-1右边的最大值决定，两者较小值减去array[1]就得到了1处的蓄水量，指针a往右移，那边最大值较小，那边指针往中间移。
```
int WaterProblem(ArrayElem *array, int length)
{
	if (array == NULL || length <=2)
		return 0;
	ArrayElem water = 0;
	ArrayElem maxL = array[0];
	ArrayElem maxR = array[length - 1];
	ArrayElem L = 1;
	ArrayElem R = length-2;
	while (L <= R)
	{
		if (maxL < maxR)
		{
			if(array[L]<=maxL)
				water += maxL - array[L];
			else
				maxL = array[L];
			L = L + 1;
		}
		else
		{
			if (array[R] <= maxR)
				water += maxR - array[R];
			else
				maxR = array[R];
			R = R -1;
		}
	}
	return water;
}
```
# 第三题
>给定一个数组，长度大于2。找出不相交的两个数组，情况是很多的。请返回这么多情况中，两个不相交子数组最大的和。
例如：
```
[-1,3,4,-9,1,2]
```
#### 解题思路
>不相交子数组最大和，可以仿照蓄水思路一，设两个数组，正反序分别记录下i位置前后子数组最大和，然后数组对应位置相加。

>特别注意的是不相交，程序中有说明。
```
max = maxer(max, maxL + arr1[j + 1]);
```

```
ArrayElem TwoSubArraySumMax(ArrayElem *array, int length)
{
	ArrayElem max=-1000;
	ArrayElem * arr1 = (ArrayElem *)malloc(sizeof(ArrayElem)*length);
	//ArrayElem * arr2 = (ArrayElem *)malloc(sizeof(ArrayElem)*length);
	ArrayElem maxL = -1000;
	ArrayElem cur_maxL = 0;
	ArrayElem maxR = -1000;
	ArrayElem cur_maxR = 0;
	//正序求0-i序列子数组的最大和（包含i）
	//反序求length-1到0的子数组的最大和
	//第二次反序的时候可以省掉一个数组
	for (int i = length-1; i >=0; i--)
	{
		cur_maxR += array[i];
		maxR = maxer(cur_maxR, maxR);
		*(arr1 + i) = maxR;
		if (cur_maxR < 0)
			cur_maxR = 0;
	}
	for (int j =0; j < length-1; j++)
	{
		cur_maxL += array[j];
		maxL = maxer(cur_maxL, maxL);
		//因为arr1[j]存放的是length-1到j包含i的字数组最大值
		//maxL也包含j，所以不是不相交所以是arr1[j+1]
		max = maxer(max, maxL + arr1[j + 1]);
		if (cur_maxL < 0)
			cur_maxL = 0;
	}
	free(arr1);
	return max;
}
```
# 第四题    
给定一个长度为N（N>1）的整形数组arr，可以划分成左右两个部分，左部分为arr[0..K]，右部分为arr[K+1..N-1]，K可以取值的范围是[0，N-2]。求这么多划分方案中，左部分中的最大值减去右部分最大值的绝对值中，最大是多少？
例如：
```
[2,7,3,1,1]
```
当左部为[2,7,3]，右部为[1,1]时，左部分中的最大值减去右部分最大值的绝对值最大为6。最终返回6。
#### 解题思路
>1、将整个数组分为两部分——左边和右边，那么最大值一定是在其中一边；

>2、| maxL-maxR |=max-maxL或maxR ，题目目的是使前面的式子最大；

>3、假设数组最大值在左边，而右边部分一定包含array[length-1]，如果右边长>1，那么maxR只会增大（因为如果减小，那就不是右边的最大值了）；

>结果就是两种情况：
(1)max在左边，右边只包含最后一个元素；
(2)max在右边，左边只包含第一个元素；
```
ArrayElem MaxAbsBetweenLeftAndRight(ArrayElem *array, int length)
{
	ArrayElem max=-1000;
	for (int i = 0; i < length; i++)
		max=maxer(max, array[i]);
	max=maxer(max - array[length - 1], max-array[0]);
	return max;
}
```
