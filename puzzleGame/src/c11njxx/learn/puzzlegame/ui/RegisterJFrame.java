package c11njxx.learn.puzzlegame.ui;

import javax.swing.*;

public class RegisterJFrame extends JFrame {
    public RegisterJFrame() {
        this.setSize(488,500);
        //设置窗口的标题
        this.setTitle("Register for game v1.0");
        //设置窗口置顶
        this.setAlwaysOnTop(true);
        //设置关闭模式
        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        this.setVisible(true);

        getContentPane();
    }
}
