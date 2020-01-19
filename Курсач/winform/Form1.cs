using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.OleDb;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace winform
{
    public partial class Form1 : Form
    {
        public class tab1
        {
            public int code;
            public int side_number;
            public string aircraft_brand;
            public int number_of_seats;
        }
        public class tab1_2
        {
            public int code;
            public int side_number;
            public string aircraft_brand;
            public int number_of_seats;
            public int number_of_tickets_sold;
        }
        public class tab2
        {
            public int code;
            public int side_number;
            public string flight_destination;
            public int number_of_tickets_sold;
            public int cost_of_one_ticket;
        }
        List<tab1> t = new List<tab1>();
        List<tab1_2> tabs = new List<tab1_2>();
        List<tab2> tab2s = new List<tab2>();
        public static string source = @"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=E:\\Ущебка\\Курсач\\winform\\Database1.mdb";
        OleDbDataReader dataReader;
        private static OleDbConnection myconnection;
        public Form1()
        {
           

            InitializeComponent();
            myconnection = new OleDbConnection(source);
            dataGridView1.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
            dataGridView1.AllowUserToAddRows = true;
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: данная строка кода позволяет загрузить данные в таблицу "database1DataSet3.tab2". При необходимости она может быть перемещена или удалена.
            this.tab2TableAdapter3.Fill(this.database1DataSet3.tab2);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "data.tab2". При необходимости она может быть перемещена или удалена.
            this.tab2TableAdapter2.Fill(this.data.tab2);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "database1DataSet2.tab2". При необходимости она может быть перемещена или удалена.
            this.tab2TableAdapter1.Fill(this.database1DataSet2.tab2);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "database1DataSet1.tab2". При необходимости она может быть перемещена или удалена.
            this.tab2TableAdapter.Fill(this.database1DataSet1.tab2);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "database1DataSet.tab1". При необходимости она может быть перемещена или удалена.
            this.tab1TableAdapter.Fill(this.database1DataSet.tab1);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text.Length != 0 && int.TryParse(textBox1.Text, out int num))
            {
                
                string str = "SELECT Код, side_number, aircraft_brand, number_of_seats FROM tab1";

                myconnection.Open();
                OleDbCommand command = new OleDbCommand(str, myconnection);

                dataReader = command.ExecuteReader();
               

                while (dataReader.Read())
                {

                    tab1 tab = new tab1();
                    tab.code = dataReader.GetInt32(0);
                    tab.side_number = dataReader.GetInt32(1);
                    tab.aircraft_brand = dataReader.GetString(2);

                    tab.number_of_seats = dataReader.GetInt32(3);
                    t.Add(tab);

                }
                list1();
                myconnection.Close();
                str = "SELECT Код, side_number, flight_destination, number_of_tickets_sold, cost_of_one_ticket FROM tab2";
                myconnection.Open();
                command = new OleDbCommand(str, myconnection);
                dataReader = command.ExecuteReader();

                while (dataReader.Read())
                {
                    tab2 _tab = new tab2();
                    _tab.code = dataReader.GetInt32(0);
                    _tab.side_number = dataReader.GetInt32(1);
                    _tab.flight_destination = dataReader.GetString(2);
                    _tab.number_of_tickets_sold = dataReader.GetInt32(3);
                    _tab.cost_of_one_ticket = dataReader.GetInt32(4);
                    tab2s.Add(_tab);

                }
                myconnection.Close();
                dataGridView3.Columns.Add("aircraft_brand", "aircraft_brand");
                
                list2();
                
            }
            else
            {
                Application.Exit();
            }
        }



        private void list2()
        {
            tab1_2 temp = new tab1_2();
            temp.code = t[0].code;
            temp.aircraft_brand = t[0].aircraft_brand;
            temp.side_number = t[0].side_number;
            temp.number_of_seats = t[0].number_of_seats;
            temp.number_of_tickets_sold = tab2s[0].number_of_tickets_sold;
            tabs.Add(temp);
            List<string> s = new List<string>();
            s.Add(tab2s[0].flight_destination);
            for (int i = 1; i < tab2s.Count; i++)
            {
                s.Add("");
                int coun = 0;
                string str = tab2s[i].flight_destination;
                for (int j = 0; j < s.Count; j++)
                {
                    if (str != s[j])
                    {
                        coun++;
                    }
                }
                if (coun == s.Count)
                {

                    s.Remove("");
                    s.Add(tab2s[i].flight_destination);
                }
            }
            for (int i = 0; i < s.Count; i++)
            {
                if (s[i] == "")
                {
                    s.Remove(s[i]);
                }
            }
            for (int i = 0; i < s.Count; i++)
            {
                dataGridView3.Columns.Add(s[i], s[i]);

                //dataGridView3.Columns.Add(tab2s[i].flight_destination, tab2s[i].flight_destination);

            }
            dataGridView3.Rows.Add(temp.aircraft_brand);

            dataGridView3.Rows[0].Cells[1].Value = "True";
            for (int i = 2; i < s.Count(); i++)
            {
                dataGridView3.Rows[0].Cells[i].Value = "False";
            }
            for (int i = 1; i < t.Count(); i++)
            {

                temp = new tab1_2();
                if (tabs.Find((x) => x.aircraft_brand == t[i].aircraft_brand)== null)
                {
                    temp.code = t[i].code;
                    temp.aircraft_brand = t[i].aircraft_brand;
                    temp.side_number = t[i].side_number;
                    temp.number_of_seats = t[i].number_of_seats;
                    temp.number_of_tickets_sold = tab2s[i].number_of_tickets_sold;
                    tabs.Add(temp);

                    dataGridView3.Rows.Add(temp.aircraft_brand);
                    
                    for (int j = 1; j < dataGridView3.Columns.Count; j++)
                    {
                        if (dataGridView3.Columns[j].Name == tab2s[i].flight_destination)
                        {
                            dataGridView3.Rows[i].Cells[j].Value = "True";
                        }
                        else
                        {
                            if (dataGridView3.Rows[i].Cells[j].Value == null)
                            {
                                dataGridView3.Rows[i].Cells[j].Value = "False";
                            }
                        }
                    }
                }
                else
                {
                    int c = t.Find((x) => x.aircraft_brand == t[i].aircraft_brand).code - 1;
                    tabs[c].number_of_seats += t[i].number_of_seats;
                    tabs[c].number_of_tickets_sold += tab2s[i].number_of_tickets_sold;
                    for (int j = 0; j < dataGridView3.Columns.Count; j++)
                    {
                        if (dataGridView3.Columns[j].Name == tab2s[i].flight_destination)
                        {
                            dataGridView3.Rows[c].Cells[j].Value = "True";
                        }
                        else
                        {
                            if (dataGridView3.Rows[c].Cells[j].Value == null)
                            {
                                dataGridView3.Rows[c].Cells[j].Value = "False";
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < tabs.Count(); i++)
            {
                listBox2.Items.Add(tabs[i].aircraft_brand + "  " + string.Format("{0:0.##}", Convert.ToDouble(tabs[i].number_of_tickets_sold) / Convert.ToDouble(tabs[i].number_of_seats) * 100) + "%");

            }
        }

        private void list1 ()
        {
            List<string> g = new List<string>();
            foreach (tab1 i in t)
            {
                if (i.number_of_seats < Convert.ToInt32(textBox1.Text) && g.Find((x) => x == i.aircraft_brand) != i.aircraft_brand)
                {
                    g.Add(i.aircraft_brand);
                    listBox1.Items.Add(i.aircraft_brand);
                }
            }
        }
        private void fillBy1ToolStripButton_Click(object sender, EventArgs e)
        {
            try
            {
                this.tab1TableAdapter.FillBy1(this.database1DataSet.tab1);
            }
            catch (System.Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }

        }
    }
}
