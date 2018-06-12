/*
在点点和评评的世界里有一个城市，城市是一个树形结构，由n个节点组成，有n-1条双向边把这些节点连在了一起（即在任意两个节点AB之间都存在从A到B的路径）。每条边都有一个边权，表示通过这条边需要的时间。
    现在点点和评评想要从他们所在的S点到T点参加会议，他们想要在过程中体会旅途的乐趣，即好好欣赏每条边上的风景。详细地说，对于每条边，都有一个值l，l表示在从S点到T点的过程中，最少需要经过这条边的次数。因为会期将至，所以点点和评评想要在看够风景的情况下，花费尽可能少的时间。
    点点和评评一共想询问m组这样的S和T，每组询问单独考虑，对于某一组特定的询问，他们想知道最少需要花费的时间。
输入描述:
第一行一个整数n(1 ≤ n ≤ 100,000)表示点数。
接下来n-1行，每行四个整数x, y, z, l(1 ≤ x, y ≤ n, 1 ≤ z, l ≤ 1,000,000,000)，表示从x到y之间有一条边权为z的边，并且这条边至少要经过l次。
数据保证没有重边和自环。
接下来一个整数m(1 ≤ m ≤ 100,000)表示询问组数。
接下来m行，每行两个整数S, T(1 ≤ S, T ≤ n)表示一组询问。
输出描述:
输出m行，每行一个整数表示答案，因为答案可能很大，请输出答案 mod 1,000,000,007的值。
示例1
输入
3
1 2 10 1  
2 3 20 2
2
1 3
3 2
输出
70
80
说明
路径为：
1->2->3->2->3
3->2->1->2->3->2
*/