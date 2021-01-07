using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp15
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        WebBrowser WB = new WebBrowser();
        private void button1_Click(object sender, EventArgs e)
        {
            
            WB.Navigate("http://192.168.1.130/?lighton");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            WB.Navigate("http://192.168.1.130/?lightoff");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            WB.Navigate("http://192.168.1.130/?blinklight");
        }
    }
}
