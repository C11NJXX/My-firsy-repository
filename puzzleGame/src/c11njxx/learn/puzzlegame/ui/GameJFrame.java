package c11njxx.learn.puzzlegame.ui;

import javax.swing.*;
import java.util.Random;

public class GameJFrame extends JFrame {

    //创建二维数组(member)
    int[][] data  = new int[4][4];

    public GameJFrame() {
        //初始化菜单
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

    private void initData() {
        //创建一维数组
        int[] tempArr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
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
            data[i/4][i%4] = tempArr[i];
        }
    }

    //初始化图片
    private void initImage() {
        //利用循环添加图片
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int num = data[i][j];
                //创建ImageIcon对象（图片）
                //创建JLable对象，相当于管理图片的容器
                JLabel jLabel = new JLabel(new ImageIcon("C:\\Code_gitee\\puzzleGame\\image\\sport\\sport3\\" + num + ".jpg"));
                //设置坐标位置
                jLabel.setBounds(105 * j, 105 * i, 105, 105);
                this.getContentPane().add(jLabel);
            }
        }
    }

    //初始化菜单
    private void initMenu() {
        //创建JMenuBar对象
        JMenuBar jMenuBar = new JMenuBar();

        //创建JMenu对象
        JMenu functionMenu = new JMenu("Function");
        JMenu aboutUsMenu = new JMenu("aboutUs");
        //创建JMenuItem对象
        JMenuItem replayItem = new JMenuItem("replay");
        JMenuItem reLoginItem = new JMenuItem("reLogin");
        JMenuItem closeItem = new JMenuItem("close");
        JMenuItem qrCode = new JMenuItem("qrCode");
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
    }
}
