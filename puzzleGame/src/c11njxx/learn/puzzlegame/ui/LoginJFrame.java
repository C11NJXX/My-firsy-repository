package c11njxx.learn.puzzlegame.ui;

import c11njxx.learn.puzzlegame.domain.User;
import c11njxx.learn.puzzlegame.Util.CodeUtil;
import javax.swing.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;

public class LoginJFrame extends JFrame implements MouseListener {

    static ArrayList<User> allUsers = new ArrayList<>();
    static {
        allUsers.add(new User("zhangsan","123"));
        allUsers.add(new User("lisi","1234"));
    }


    JButton login = new JButton();
    JButton register = new JButton();

    JTextField username = new JTextField();
    //JTextField password = new JTextField();
    JPasswordField password = new JPasswordField();
    JTextField code = new JTextField();

    //��ȷ����֤��
    JLabel rightCode = new JLabel();


    public LoginJFrame() {
        //��ʼ������
        initJFrame();

        //������������������
        initView();


        //�õ�ǰ������ʾ����
        this.setVisible(true);
    }

    public void initView() {
        //1. ����û�������
        JLabel usernameText = new JLabel(new ImageIcon("C:\\Code_github\\puzzleGame\\image\\login\\�û���.png"));
        usernameText.setBounds(116, 135, 47, 17);
        this.getContentPane().add(usernameText);

        //2.����û��������

        username.setBounds(195, 134, 200, 30);
        this.getContentPane().add(username);

        //3.�����������
        JLabel passwordText = new JLabel(new ImageIcon("C:\\Code_github\\puzzleGame\\image\\login\\����.png"));
        passwordText.setBounds(130, 195, 32, 16);
        this.getContentPane().add(passwordText);

        //4.���������
        password.setBounds(195, 195, 200, 30);
        this.getContentPane().add(password);


        //��֤����ʾ
        JLabel codeText = new JLabel(new ImageIcon("C:\\Code_github\\puzzleGame\\image\\login\\��֤��.png"));
        codeText.setBounds(133, 256, 50, 30);
        this.getContentPane().add(codeText);

        //��֤��������
        code.setBounds(195, 256, 100, 30);
        this.getContentPane().add(code);


        String codeStr = CodeUtil.getCode();
        //��������
        rightCode.setText(codeStr);
        //������¼�
        rightCode.addMouseListener(this);
        //λ�úͿ��
        rightCode.setBounds(300, 256, 50, 30);
        //��ӵ�����
        this.getContentPane().add(rightCode);

        //5.��ӵ�¼��ť
        login.setBounds(123, 310, 128, 47);
        login.setIcon(new ImageIcon("C:\\Code_github\\puzzleGame\\image\\login\\��¼��ť.png"));
        //ȥ����ť�ı߿�
        login.setBorderPainted(false);
        //ȥ����ť�ı���
        login.setContentAreaFilled(false);
        //����¼��ť������¼�
        login.addMouseListener(this);
        this.getContentPane().add(login);

        //6.���ע�ᰴť
        register.setBounds(256, 310, 128, 47);
        register.setIcon(new ImageIcon("C:\\Code_github\\puzzleGame\\image\\login\\ע�ᰴť.png"));
        //ȥ����ť�ı߿�
        register.setBorderPainted(false);
        //ȥ����ť�ı���
        register.setContentAreaFilled(false);
        //��ע�ᰴť������¼�
        register.addMouseListener(this);
        this.getContentPane().add(register);


        //7.��ӱ���ͼƬ
        JLabel background = new JLabel(new ImageIcon("C:\\Code_github\\puzzleGame\\image\\login\\background.png"));
        background.setBounds(0, 0, 470, 390);
        this.getContentPane().add(background);

    }


    public void initJFrame() {
        this.setSize(488, 430);//���ÿ��
        this.setTitle("ƴͼ��Ϸ V1.0��¼");//���ñ���
        this.setDefaultCloseOperation(3);//���ùر�ģʽ
        this.setLocationRelativeTo(null);//����
        this.setAlwaysOnTop(true);//�ö�
        this.setLayout(null);//ȡ���ڲ�Ĭ�ϲ���
    }



    //���
    @Override
    public void mouseClicked(MouseEvent e) {
        if (e.getSource() == login) {
            System.out.println("����˵�¼��ť");
            //��ȡ�����ı�������е�����
            String usernameInput = username.getText();
            String passwordInput = password.getText();
            //��ȡ�û��������֤��
            String codeInput = code.getText();

            //����һ��User����
            User userInfo = new User(usernameInput, passwordInput);
            System.out.println("�û�������û���Ϊ" + usernameInput);
            System.out.println("�û����������Ϊ" + passwordInput);

            if (codeInput.length() == 0) {
                showJDialog("��֤�벻��Ϊ��");
            } else if (usernameInput.length() == 0 || passwordInput.length() == 0) {
                //У���û����������Ƿ�Ϊ��
                System.out.println("�û�����������Ϊ��");

                //����showJDialog������չʾ����
                showJDialog("�û�����������Ϊ��");


            } else if (!codeInput.equalsIgnoreCase(rightCode.getText())) {
                showJDialog("��֤���������");
            } else if (contains(userInfo)) {
                System.out.println("�û�����������ȷ���Կ�ʼ����Ϸ��");
                //�رյ�ǰ��¼����
                this.setVisible(false);
                //����Ϸ��������
                //��Ҫ�ѵ�ǰ��¼���û������ݸ���Ϸ����
                new GameJFrame();
            } else {
                System.out.println("�û������������");
                showJDialog("�û������������");
            }
        } else if (e.getSource() == register) {
            System.out.println("�����ע�ᰴť");
        } else if (e.getSource() == rightCode) {
            System.out.println("������֤��");
            //��ȡһ���µ���֤��
            String code = CodeUtil.getCode();
            rightCode.setText(code);
        }
    }


    public void showJDialog(String content) {
        //����һ���������
        JDialog jDialog = new JDialog();
        //���������ô�С
        jDialog.setSize(200, 150);
        //�õ����ö�
        jDialog.setAlwaysOnTop(true);
        //�õ������
        jDialog.setLocationRelativeTo(null);
        //���򲻹ر���Զ�޷���������Ľ���
        jDialog.setModal(true);

        //����Jlabel����������ֲ���ӵ�������
        JLabel warning = new JLabel(content);
        warning.setBounds(0, 0, 200, 150);
        jDialog.getContentPane().add(warning);

        //�õ���չʾ����
        jDialog.setVisible(true);
    }

    //���²���
    @Override
    public void mousePressed(MouseEvent e) {
        if (e.getSource() == login) {
            login.setIcon(new ImageIcon("C:\\Code_github\\puzzleGame\\image\\login\\��¼����.png"));
        } else if (e.getSource() == register) {
            register.setIcon(new ImageIcon("C:\\Code_github\\puzzleGame\\image\\login\\ע�ᰴ��.png"));
        }
    }


    //�ɿ���ť
    @Override
    public void mouseReleased(MouseEvent e) {
        if (e.getSource() == login) {
            login.setIcon(new ImageIcon("C:\\Code_github\\puzzleGame\\image\\login\\��¼��ť.png"));
        } else if (e.getSource() == register) {
            register.setIcon(new ImageIcon("C:\\Code_github\\puzzleGame\\image\\login\\ע�ᰴť.png"));
        }
    }

    //��껮��
    @Override
    public void mouseEntered(MouseEvent e) {

    }

    //��껮��
    @Override
    public void mouseExited(MouseEvent e) {

    }

    //�ж��û��ڼ������Ƿ����
    public boolean contains(User userInput){
        for (int i = 0; i < allUsers.size(); i++) {
            User rightUser = allUsers.get(i);
            if(userInput.getUsername().equals(rightUser.getUsername()) && userInput.getPassword().equals(rightUser.getPassword())){
                //����ͬ�Ĵ�����ڣ�����true������Ĳ���Ҫ�ٱ���
                return true;
            }
        }
        //ѭ������֮��û���ҵ��ͱ�ʾ������
        return false;
    }


}
