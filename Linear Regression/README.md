Though our problem was a classification algorithm, but it is also possible to break it into parts which is individually a regression problem and we can then combine those result and classify it. We have the safe range for every feature.<br>
We used linear regression to find individual value for PH, Turbidity etc. Then check if it is into the safe range or not.<br>
Linear regression takes the training dataset and sends it to the learning algorithm and learning algorithm returns an equation.<br>
X ----   Y<br>
1 ----   31<br>
2 ----   29<br>
3 ----   29<br>
<br>
X is the input index that indicates the day of the year. And Y indicates the temperature on X’th day. After passing the training dataset we get an equation that is similar to 𝑌=𝐴+𝐵𝑋<br>
Then we can find the Y for any X. After finding the expected temperature, PH, Turbidity and EC, we check if it is the safe range or not. Then we declares it is safe or unsafe.<br>
