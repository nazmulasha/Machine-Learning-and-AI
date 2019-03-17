K-Nearest Neighbor, broadly known as KNN. It is a classification algorithm that classifies by checking the Euclidian distance from test to trains. This one is very straight forward algorithm.<br>
First of all, we split the dataset into two different parts with the ratio of 70:30. 70% data for training and rest of the 30% data for testing.<br>
For each of test instance, we find the Euclidian distance by all the features the store the distance in a vector. After finding distances from all the training instances, we sort the distances and consider closest k neighbors. Then depending on the majority it decides which class this test data belong to.<br>
This algorithm uses very simple calculation, so it’s an easy task for a normal processor and it is very fast.<br>
𝐸𝑢𝑐𝑙𝑖𝑑𝑖𝑎𝑛 𝐷𝑖𝑠𝑡𝑎𝑛𝑐𝑒 𝑑(𝑎,𝑏)=√(𝑎1−𝑏1)2+(𝑎2−𝑏2)2+⋯+(𝑎𝑛−𝑏𝑛)2<br>
