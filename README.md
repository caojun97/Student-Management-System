# Student-Management-System

## 一、简介

目前正在学习算法与数据结构，学习线性表-单链表这一章节时，对于教材的知识点产生不解。教程上只有单一理论介绍，缺少实践操作部分，那么为什么不通过将所学知识融合到实践中呢？

学生管理系统项目就创建了，既然是关于学生的，肯定要考虑实际的学生因素。学生属性有 `学号`、 `姓名`、 `性别`、 `年龄`，基本要素齐全了，接下就要考虑技术选型。我们可以直接使用结构体数组实现，但我们不知道具体拥有多少个学生，若申请结构体数组过大就会浪费大量内存空间，若申请结构体数组过小就会存放不小多余的学生。

我们需要的是当加入一个学生时，申请一个学生大小空间，做到按需申请。这种实现方式就是 `链表`

## 二、功能介绍

学生管理系统的基本功能需要定下来，初步可以考虑的有：`显示所有学生信息`、`添加一名学生信息`、`查询一名学生信息`、`删除一名学生信息`、`保存所有学生信息`、`退出学生管理系统`

### 2-1 显示所有学生信息

* **系统初始化时，没有任何学生数据**

  ![image-20230105114132784](README.assets/image-20230105114132784.png)

* **添加部分学生后，可以显示所有学生信息**

  ![image-20230105120426055](README.assets/image-20230105120426055.png)

### 2-2 添加一名学生信息

学生信息的属性有限制和约束的，在用户输入时会进行提示，输入完毕后也要进行检查

![image-20230105114439523](README.assets/image-20230105114439523.png)

### 2-3 查询一名学生信息

支持通过 `学号` 来查询一名学生信息

![img](README.assets/SNAGHTMLae0ae99.PNG)

### 2-4 删一名学生信息

支持通过 `学号` 来删除一名学生信息

![img](README.assets/SNAGHTMLae1a00e.PNG)

验证是否真的删除成功

![image-20230105120936919](README.assets/image-20230105120936919.png)

### 2-5 保存所有学生信息

支持以 `json` 格式保存所有学生信息

![image-20230105121130920](README.assets/image-20230105121130920.png)

验证是否保存成功

![image-20230105121238924](README.assets/image-20230105121238924.png)

### 2-6 退出学生管理系统

![image-20230105121324089](README.assets/image-20230105121324089.png)



## 三、版本迭代

当前版本可能存在bug，欢迎大家指出。

而且当前版本功能有限，下一版本可能添加额外的功能，例如读取 `json` 格式文件到学生管理系统、多种条件查询方式







