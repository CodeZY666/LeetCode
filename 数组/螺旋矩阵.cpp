/*
problem:给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
data:2026/3/3
Author by:ZY
说明：循环变量原则：在循环中，尽量不要修改循环变量的值，以避免引起混乱和错误。
循环变量应该只用于控制循环的迭代次数，而不应该被用来存储其他数据或进行其他操作。
如果需要在循环中使用其他变量来存储数据，应该使用不同的变量名，以保持代码的清晰和可读性。*/
class Solution{
public:
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> result (n, vector<int>(n, 0));
        int startx = 0; int starty = 0; // 每一圈的起点坐标
        int loop = n/2; // 循环的层数 
        int count = 1; // 给每个元素赋值
        int offset = 1; // 控制每个循环的长度
        int i,j;
        while(loop--){
            // 第一行
            for(j = starty; j < n - offset; j++){
                result[startx][j] = count++;
            }
            // 第j列
            for(i = startx; i < n - offset; i++){
                result[i][j] = count++;
            }
            // 第i行
            for(;j > starty; j--){
                result[i][j] = count++;
            }
            // 第1列
            for(;i>startx; i--){
            result[i][starty] = count++;
            }
            //第二圈开始更改起点坐标
            startx++;
            starty++;
            offset++;
        }
        // 中间元素单独处理
        if(n%2 == 1){
             result[i][j] = count;
        }
        return result;
    }
};
