using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        private MP3 mp3Player;
        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog dlg = new OpenFileDialog())
            {
                dlg.Filter = "Mp3 File|*.mp3";
                dlg.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyComputer);

                if (dlg.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    mp3Player = new MP3(dlg.FileName);
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (mp3Player != null)
            {
                // mp3Player.Stop();
                mp3Player.Play();
            }
            else MessageBox.Show("Файл не выбран!");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (mp3Player != null)
                mp3Player.Stop();
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            if (mp3Player != null)
                mp3Player.SetVolume(trackBar1.Value);
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (mp3Player != null) mp3Player.Stop();
            string path = listBox1.SelectedItem.ToString();
            mp3Player = new MP3(path);
            if (mp3Player!=null) mp3Player.Play();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            string path = null;
            using (var dialog = new FolderBrowserDialog())
                if (dialog.ShowDialog() == DialogResult.OK)
                    path = dialog.SelectedPath;
            string[] files = null;
            try { files = Directory.GetFiles(path, "*.mp3", SearchOption.AllDirectories); }
            catch { }
            if (files != null)
            {
                foreach (string file in files)
                {
                    listBox1.Items.Add(file);
                }
            }
        }
    }
}
