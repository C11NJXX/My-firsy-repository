package c11njxx.learn.puzzlegame.ui;

import javax.swing.*;
import javax.swing.border.BevelBorder;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Random;

//在整个界面添加监听，实现接口
public class GameJFrame extends JFrame implements KeyListener, ActionListener {

    //创建二维数组(member)
    int[][] data = new int[4][4];
    //存储空图片的位置
    int x = 0;
    int y = 0;
    //定义一个String变量，记录路径,换图片时不用再到处修改
    String path = "C:\\Code_github\\puzzleGame\\image\\sport\\sport3\\";
    //定义一个正确数组，用于后期比较
    int[][] win = new int[][] {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,0}
    };
    //定义变量记录步数
    int step = 0;
    //将菜单中的对象放在成员位置方便访问
    //创建JMenuItem对象
    JMenuItem replayItem = new JMenuItem("replay");
    JMenuItem reLoginItem = new JMenuItem("reLogin");
    JMenuItem closeItem = new JMenuItem("close");
    JMenuItem qrCode = new JMenuItem("qrCode");

    public GameJFrame() {
        //初始化界面
        initJFrame();
        //初始化菜单
        initMenu();
        //初始化数据(打乱图片)
        initData();
        //初始化图片
        initImage();
        //窗口是否可见
        this.setVisible(true);

    }
    //初始化数据（打乱图片）
    private void initData() {
        //创建一维数组
        int[] tempArr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        //打乱一维数组
        Random r = new Random();
        for (int i = 0; i < tempArr.length; i++) {
            //获取随机索引
            int index = r.nextInt(tempArr.length);
            //交换随机索引与循环索引
            int temp = tempArr[i];
            tempArr[i] = tempArr[index];
            tempArr[index] = temp;
        }
        //测试遍历
        for (int i1 = 0; i1 < tempArr.length; i1++) {
            System.out.print(tempArr[i1] + " ");
        }
        System.out.println();

        //添加数据
        for (int i = 0; i < tempArr.length; i++) {
            if (tempArr[i] == 0) {
                x = i / 4;
                y = i % 4;
            }data[i / 4][i % 4] = tempArr[i];
//            else {
//                data[i / 4][i % 4] = tempArr[i];
//            }                        这里代码有问题，导致后期重新开始游戏的时候，有图片不能重新赋值，导致没有空白图片，不需要else让所有的都得到记录
        }
        System.out.println("x = " + x + "y =" + y);
    }

    //初始化图片
    private void initImage() {

        //清空移动前的图片，防止覆盖
        this.getContentPane().removeAll();

        //每次重新初始化图片时,都判断是否胜利
        if(isVictory()) {
            //添加胜利图标
            JLabel winJLabel = new JLabel(new ImageIcon("C:\\Code_github\\puzzleGame\\image\\win.png"));
            winJLabel.setBounds(203,283,197,73);
            this.getContentPane().add(winJLabel);
        }

        //显示步数信息
        JLabel stepCount = new JLabel("step = " + step);
        stepCount.setBounds(50,30,100,20);
        this.getContentPane().add(stepCount);

        //利用循环添加图片
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int num = data[i][j];
                //创建ImageIcon对象（图片）
                //创建JLable对象，相当于管理图片的容器
                JLabel jLabel = new JLabel(new ImageIcon(path + num + ".jpg"));
                //设置坐标位置
                jLabel.setBounds(105 * j + 83, 105 * i + 134, 105, 105);
                //设置图片边框
                jLabel.setBorder(new BevelBorder(BevelBorder.LOWERED));
                this.getContentPane().add(jLabel);
            }
        }
        //先添加的在上面
        //添加背景图片
        JLabel background = new JLabel(new ImageIcon("C:\\Code_github\\puzzleGame\\image\\background.png"));
        background.setBounds(40, 40, 508, 560);
        this.getContentPane().add(background);
        //刷新界面
        this.getContentPane().repaint();
    }

    //初始化菜单
    private void initMenu() {
        //创建JMenuBar对象
        JMenuBar jMenuBar = new JMenuBar();

        //创建JMenu对象
        JMenu functionMenu = new JMenu("Function");
        JMenu aboutUsMenu = new JMenu("aboutUs");


        //给条目绑定事件
        replayItem.addActionListener(this);
        reLoginItem.addActionListener(this);
        closeItem.addActionListener(this);
        qrCode.addActionListener(this);

        //逐层添加
        functionMenu.add(replayItem);
        functionMenu.add(reLoginItem);
        functionMenu.add(closeItem);

        aboutUsMenu.add(qrCode);

        jMenuBar.add(functionMenu);
        jMenuBar.add(aboutUsMenu);

        //设置菜单
        this.setJMenuBar(jMenuBar);
    }


    private void initJFrame() {
        //设置窗口大小
        this.setSize(603, 680);
        //设置窗口的标题
        this.setTitle("Puzzle Game v1.0");
        //设置窗口置顶
        this.setAlwaysOnTop(true);
        //设置关闭模式
        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        //设置放置模式,取消默认模式
        this.setLayout(null);
        //为界面添加键盘监听(上下左右，查看完整图片，作弊码
        this.addKeyListener(this);//this相当于从本实现类中调用相应的事件响应方法
    }

    @Override
    public void keyTyped(KeyEvent e) {

    }

    //按下不松时调用该方法
    @Override
    public void keyPressed(KeyEvent e) {
        int keycode = e.getKeyCode();
        if (keycode == 65) {
            //胜利后结束，不能再进行显示完整图片操作
            if(isVictory()){
                return;
            }
            //把界面所有图片删除
            this.getContentPane().removeAll();
            //完整图片
            JLabel all = new JLabel(new ImageIcon(path + "all.jpg"));
            //设置位置宽高
            all.setBounds(83, 134, 420, 420);
            //图片加载到界面
            this.getContentPane().add(all);
            //添加背景图片
            JLabel background = new JLabel(new ImageIcon(path + "background.png"));
            background.setBounds(40, 40, 508, 560);
            this.getContentPane().add(background);
            //刷新界面
            this.getContentPane().repaint();
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {
        //胜利后结束，不能再进行移动操作
        if(isVictory()){
            return;
        }
        //对上下左右进行判断，左：37 上：38 右：39 下：40
        int keycode = e.getKeyCode();
        switch (keycode) {
            case 37 -> {
                System.out.println("Left moving");
                //逻辑，交换二维数组中x,y+1 与 x，y的位置，注意越界问题,这里相当于重新赋值0
                if (y == 3) {
                    return;//无法实现将边界空白方块右的图片左移
                }
                data[x][y] = data[x][y + 1];
                data[x][y + 1] = 0;
                y++;//新的空图片位置更新

                //移动一次，step自增
                step++;

                //再重新用循环打印一边图片
                initImage();
            }
            case 38 -> {
                System.out.println("Up moving");
                //逻辑，交换二维数组中x+1,y 与 x，y的位置，注意越界问题,这里相当于重新赋值0
                if (x == 3) {
                    return;//无法实现将边界空白方块下的图片上移
                }
                data[x][y] = data[x + 1][y];
                data[x + 1][y] = 0;
                x++;//新的空图片位置更新

                //移动一次，step自增
                step++;

                //再重新用循环打印一边图片
                initImage();
            }
            case 39 -> {
                System.out.println("Right moving");
                //逻辑，交换二维数组中x,y-1 与 x，y的位置，注意越界问题,这里相当于重新赋值0
                if (y == 0) {
                    return;//无法实现将边界空白方块左下的图片右移
                }
                data[x][y] = data[x][y - 1];
                data[x][y - 1] = 0;
                y--;//新的空图片位置更新

                //移动一次，step自增
                step++;

                //再重新用循环打印一边图片
                initImage();
            }
            case 40 -> {
                System.out.println("Down moving");
                //逻辑，交换二维数组中x-1,y 与 x，y的位置，注意越界问题,这里相当于重新赋值0
                if (x == 0) {
                    return;//无法实现将边界空白方块上的图片下移
                }
                data[x][y] = data[x - 1][y];
                data[x - 1][y] = 0;
                x--;//新的空图片位置更新

                //移动一次，step自增
                step++;

                //再重新用循环打印一边图片
                initImage();
            }
            case 65 -> {
                initImage();//判断松开A键后，恢复为之前的状态，二维数组并未发生变化
            }
            case 87 -> {
                //作弊码W
                //直接改变二维数组
                data = new int[][] {
                        {1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,0}
                };
                //x,y位置改变
                x = 3;
                y = 3;
                //重新加载图片
                initImage();
            }
        }
    }

    //判断是否胜利
    public boolean isVictory() {
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < data[i].length; j++) {
                if(data[i][j] != win[i][j]) {
                    //只要有一个数据不一样返回false
                    return false;
                }
            }
        }
        //全部相同返回true
        return true;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        //获取当前被点击的对象
        Object obj = e.getSource();
        if(obj == replayItem){
            System.out.println("replay");
            //重新游戏
            //计步器清零（注意顺序）
            step = 0;
            //再次打乱顺序
            initData();
            //重新加载图片
            initImage();

        }else if(obj == reLoginItem) {
            System.out.println("reLogin");
            //关闭当前界面（设置不可见）
            this.setVisible(false);
            //打开登陆界面
            new LoginJFrame();
        }else if(obj == closeItem) {
            System.out.println("Exit");
            //关闭虚拟机
            System.exit(0);
        }else if(obj == qrCode) {
            System.out.println("show qrCode");
            //创建弹框对象
            JDialog jDialog = new JDialog();
            JLabel jLabel = new JLabel(new ImageIcon("C:\\Code_github\\puzzleGame\\image\\about.png"));
            jLabel.setBounds(0,0,258,258);
            jDialog.getContentPane().add(jLabel);
            //给弹框设置大小
            jDialog.setSize(344,344);
            //弹框置顶
            jDialog.setAlwaysOnTop(true);
            //弹框居中
            jDialog.setLocationRelativeTo(null);
            //弹框不关闭无法操作下面界面
            jDialog.setModal(true);
            //显示弹框
            jDialog.setVisible(true);
        }
    }
}
