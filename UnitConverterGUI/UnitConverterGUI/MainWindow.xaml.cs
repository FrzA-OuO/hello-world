using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace UnitConverterGUI
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    /// 
    public class Unit
    {
        public string Display { get; set; }
        public string Arg { get; set; }
    }
    public class UnitType
    {
        public string Display { get; set; }
        public string Arg { get; set; }
    }


    public partial class MainWindow : Window
    {
        int focusedNumber = 1;
        Color activedColor = Color.FromArgb(255, 255, 72, 0);
        Color deactivedColor = Color.FromArgb(255, 0, 0, 0);

        string unittype = "-weight";

        void Convert(int _focused)
        {
            if (_focused == 1)
            {

            }
            else if (_focused == 2)
            {

            }
        }

        public MainWindow()
        {
            InitializeComponent();
        }

        List<UnitType> listUnit = new List<UnitType>();
        List<Unit> listWeight = new List<Unit>();
        List<Unit> listLength = new List<Unit>();
        List<Unit> listPressure = new List<Unit>();
        List<Unit> listForce = new List<Unit>();

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            if (!System.IO.File.Exists("arg.exe")) // there's no "arg.exe" in the same path
            {
                MessageBox.Show( "there's no \"arg.exe\" in " + System.Environment.CurrentDirectory, "Can't find file", MessageBoxButton.OK, MessageBoxImage.Error);
                this.Close();
            }



            listUnit.Add(new UnitType { Display = "长度转换", Arg = "-length" });
            listUnit.Add(new UnitType { Display = "质量转换", Arg = "-weight" });
            listUnit.Add(new UnitType { Display = "力转换", Arg = "-force" });
            listUnit.Add(new UnitType { Display = "压强转换", Arg = "-pressure" });

            typeSelect.ItemsSource = listUnit;
            typeSelect.SelectedIndex = 0;

            listLength.Add(new Unit { Display = "千米(kg)", Arg = "km" });
            listLength.Add(new Unit { Display = "米(m)", Arg = "m" });
            listLength.Add(new Unit { Display = "分米(dm)", Arg = "dm" });
            listLength.Add(new Unit { Display = "厘米(cm)", Arg = "cm" });
            listLength.Add(new Unit { Display = "毫米(mm)", Arg = "mm" });
            listLength.Add(new Unit { Display = "微米(μm)", Arg = "mum" });
            listLength.Add(new Unit { Display = "纳米(nm)", Arg = "nm" });
            listLength.Add(new Unit { Display = "海里(nmi)", Arg = "nmi" });
            listLength.Add(new Unit { Display = "英里(mi)", Arg = "mi" });
            listLength.Add(new Unit { Display = "弗隆(fur)", Arg = "fur" });
            listLength.Add(new Unit { Display = "英寻(fm)", Arg = "fm" });
            listLength.Add(new Unit { Display = "码(yd)", Arg = "yd" });
            listLength.Add(new Unit { Display = "英尺(ft)", Arg = "ft" });
            listLength.Add(new Unit { Display = "英寸(in)", Arg = "in" });
            listLength.Add(new Unit { Display = "公里(gongli)", Arg = "gongli" });
            listLength.Add(new Unit { Display = "里(li)", Arg = "li" });
            listLength.Add(new Unit { Display = "丈(zhang)", Arg = "zhang" });
            listLength.Add(new Unit { Display = "尺(chi)", Arg = "chi" });
            listLength.Add(new Unit { Display = "寸(cun)", Arg = "cun" });
            listLength.Add(new Unit { Display = "分(fen)", Arg = "fen" });
            listLength.Add(new Unit { Display = "厘(lii)", Arg = "lii" });
            listLength.Add(new Unit { Display = "毫(hao)", Arg = "hao" });

            listWeight.Add(new Unit { Display = "吨(t)", Arg = "t" });
            listWeight.Add(new Unit { Display = "千克(kg)", Arg = "kg" });
            listWeight.Add(new Unit { Display = "克(g)", Arg = "g" });
            listWeight.Add(new Unit { Display = "毫克(mg)", Arg = "mg" });
            listWeight.Add(new Unit { Display = "微克(μg)", Arg = "mug" });
            listWeight.Add(new Unit { Display = "公担(q)", Arg = "q" });
            listWeight.Add(new Unit { Display = "磅(lb)", Arg = "lb" });
            listWeight.Add(new Unit { Display = "盎司(oz)", Arg = "oz" });
            listWeight.Add(new Unit { Display = "克拉(ct)", Arg = "ct" });
            listWeight.Add(new Unit { Display = "格令(gr)", Arg = "gr" });
            listWeight.Add(new Unit { Display = "打兰(dr)", Arg = "dr" });
            listWeight.Add(new Unit { Display = "担(dan)", Arg = "dan" });
            listWeight.Add(new Unit { Display = "斤(jin)", Arg = "jin" });
            listWeight.Add(new Unit { Display = "钱(qian)", Arg = "qian" });
            listWeight.Add(new Unit { Display = "两(liang)", Arg = "liang" });
            listWeight.Add(new Unit { Display = "台湾斤(jin(tw))", Arg = "jin（tw)" });

            listPressure.Add(new Unit { Display = "帕斯卡(Pa)", Arg = "pa" });
            listPressure.Add(new Unit { Display = "兆帕(MPa)", Arg = "mpa" });
            listPressure.Add(new Unit { Display = "磅力每平方英寸(psi)", Arg = "psi" });

            listForce.Add(new Unit { Display = "牛(N)", Arg = "N" });
            listForce.Add(new Unit { Display = "达因(Dyne, dyn)", Arg = "dyn" });
            listForce.Add(new Unit { Display = "磅力(lbf)", Arg = "lbf" });

            unitSelect1.SelectedIndex = 0;
            unitSelect2.SelectedIndex = 0;
        }

        private void number1_GotFocus(object sender, RoutedEventArgs e)
        {
            focusedNumber = 1;
            number1.Foreground = new SolidColorBrush(activedColor);
            number2.Foreground = new SolidColorBrush(deactivedColor);
        }



        private void converterButtun_Click(object sender, RoutedEventArgs e)
        {
            // string cmd = ("arg " + unittype + " " + number1.Text.ToString() + " " + "kg " + "g");

            System.Diagnostics.Process p = new System.Diagnostics.Process();
            p.StartInfo.FileName = "arg.exe";//要执行的程序名称   

            if (focusedNumber == 1)
            {
                Console.WriteLine(unittype + " " + number1.Text.ToString() + " " + unitSelect1.SelectedValue.ToString() + " " + unitSelect2.SelectedValue.ToString());
                p.StartInfo.Arguments = unittype + " " + number1.Text.ToString() + " " + unitSelect1.SelectedValue.ToString() + " " + unitSelect2.SelectedValue.ToString();
            }
            else if( focusedNumber == 2)
            {
                Console.WriteLine(unittype + " " + number2.Text.ToString() + " " + unitSelect2.SelectedValue.ToString() + " " + unitSelect1.SelectedValue.ToString());
                p.StartInfo.Arguments = unittype + " " + number2.Text.ToString() + " " + unitSelect2.SelectedValue.ToString() + " " + unitSelect1.SelectedValue.ToString();
            }

            p.StartInfo.UseShellExecute = false;
            p.StartInfo.RedirectStandardInput = true;//可能接受来自调用程序的输入信息  
            p.StartInfo.RedirectStandardOutput = true;//由调用程序获取输出信息   
            p.StartInfo.CreateNoWindow = true;//不显示程序窗口   
            p.Start();//启动程序   
                      //向CMD窗口发送输入信息：   
            // p.StandardInput.WriteLine("arg " + unittype + " " + number1.Text.ToString() + " " + "kg " + "g");
            //-ss表示搜索到指定的时间 -i表示输入的文件 -y表示覆盖输出 -f表示强制使用的格式  

            StreamReader reader = p.StandardOutput;//截取输出流  
            string line = reader.ReadLine();//每次读取一行  
            // number2.AppendText(line + "\n");

            if (focusedNumber == 1)
            {

                number2.Text = line;
                while (!reader.EndOfStream)
                {
                    line = reader.ReadLine();
                    number2.AppendText(line + "\n");
                }
            }
            else if( focusedNumber == 2)
            {
                number1.Text = line;
                while (!reader.EndOfStream)
                {
                    line = reader.ReadLine();
                    number1.AppendText(line + "\n");
                }
            }
            p.WaitForExit();//等待程序执行完退出进程  
            p.Close();

        }

        private void number2_GotFocus(object sender, RoutedEventArgs e)
        {
            focusedNumber = 2;
            number2.Foreground = new SolidColorBrush(activedColor);
            number1.Foreground = new SolidColorBrush(deactivedColor);
        }

        private void typeSelect_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
           //  Console.WriteLine(typeSelect.SelectedItem.ToString());
           //  Console.WriteLine(typeSelect.SelectedValue.ToString());
            if (typeSelect.SelectedValue.ToString().CompareTo("-weight") == 0)
            {
                unittype = typeSelect.SelectedValue.ToString();
                unitSelect1.ItemsSource = listWeight;
                unitSelect2.ItemsSource = listWeight;
            }
            else if (typeSelect.SelectedValue.ToString().CompareTo("-length") == 0)
            {
                unittype = typeSelect.SelectedValue.ToString();
                unitSelect1.ItemsSource = listLength;
                unitSelect2.ItemsSource = listLength;
            }
            else if (typeSelect.SelectedValue.ToString().CompareTo("-force") == 0)
            {
                unittype = typeSelect.SelectedValue.ToString();
                unitSelect1.ItemsSource = listForce;
                unitSelect2.ItemsSource = listForce;
            }
            else if (typeSelect.SelectedValue.ToString().CompareTo("-pressure") == 0)
            {
                unittype = typeSelect.SelectedValue.ToString();
                unitSelect1.ItemsSource = listPressure;
                unitSelect2.ItemsSource = listPressure;
            }
            unitSelect1.SelectedIndex = 0;
            unitSelect2.SelectedIndex = 0;

        }
    }
}
