package c11njxx.learn.puzzlegame.ui;

import javax.swing.*;

public class LoginJFrame extends JFrame {
    public LoginJFrame() {
        this.setSize(488,430);
        //设置窗口的标题
        this.setTitle("Login v1.0");
        //设置窗口置顶
        this.setAlwaysOnTop(true);
        //设置关闭模式
        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        this.setVisible(true);
    }
}
