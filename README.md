


矩阵计算器 


MatCalc的所有指令格式均为“指令(操作数1, 操作数2…)”或“指令 操作数1 操作数2 …”。

		MatName = [data]


MatName = [N:x:M]
表示产生一个行向量，元素依次为“N, N+x, N+2x, …, M”，
若只有[ N:M ]而不指定x表示x=1

MatName = rand(N,M)
定义一个名为“MatName”的N*M的随机矩阵，矩阵中每个元素为一个[0,1]的随机数。若不指定M则表示M=N。若不加“MatName = ”则仅有ans等于这个随机矩阵。

MatName = zeros(N, M)
定义一个名为“MatName”的N*N的零矩阵。若不指定M则表示M=N。若不加“Matname = ”则仅有ans等于这个零矩阵。

MatName = eye(N)
定义一个名为“MatName”的N*N的单位矩阵，若不加“Matname = ”则仅有ans等于这个零矩阵。

MatName = ans
				定义一个名为“MatName”且等于ans的矩阵


四则运算、取余（返回值为计算结果）
MatCalc应具有二元普通运算和取余（+、-、*、\、%）功能。
且识别任意中缀表达式 。
矩阵求和、最大值最小值（返回值为一个数）
MatCalc可以对矩阵所有元素求和、求出矩阵中的最大值和最小值。格式如：
	sum(MatA)
	max(MatA)
	min(MatA)
四舍五入和取整（返回值为计算结果）
MatCalc包含各种取整的命令，如
	round(MatName)
	upper(MatName)
	lower(MatName)
分别表示让MatName中的元素四舍五入、向上取整、向下取整
支持嵌套定义（返回定义的矩阵）
MatCalc应支持诸如
	MatName = [ eye(3), zeros(3); 1:3, 2:2:6 ]
将定义一个MatName =
1	0	0	0	0	0
0	1	0	0	0	0
0	0	1	0	0	0
1	2	3	2	4	6

矩阵的幂（返回值为计算结果）


MatCalc应具有快速计算矩阵的幂的功能。格式为
	MatName^N
其中N应为一整数。若N是负数则表示其逆的|N|次。“^”两端可能有空格。若矩阵名后面有一个“.”表示对矩阵中每一个元素分别求幂。
矩阵的转置（返回值为计算结果）
以命令

	MatName’
表示矩阵的转置。单引号和矩阵名之间不允许有分隔符
方阵的行列式（返回值为计算结果）
MatCalc应能够计算一个方阵的行列式。格式为

	det(MatName)
此时应将返回值视作常数，而非一个1*1的矩阵


化为行最简形（返回值为计算结果）

MatCalc应能通过基本行运算将一个矩阵化为行最简形。格式为
	rref(MatName)
rref即reduced row echelon form
矩阵的逆、除法（返回值为计算结果）
MatCalc应能求方阵的逆，除法运算中若一个除数是方阵即乘以它的逆，同样，一个方阵的n次幂，若n<0即其逆的|n|次幂。格式为
	reverse(MatA)
	MatA^n
	MatA/MatB
