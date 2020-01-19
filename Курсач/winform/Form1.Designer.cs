namespace winform
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.кодDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.sidenumberDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.aircraftbrandDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.numberofseatsDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.tab1BindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.database1DataSet = new winform.Database1DataSet();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.button1 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.listBox2 = new System.Windows.Forms.ListBox();
            this.database1DataSet1BindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.database1DataSet1 = new winform.Database1DataSet1();
            this.tab1TableAdapter = new winform.Database1DataSetTableAdapters.tab1TableAdapter();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.tab2BindingSource3 = new System.Windows.Forms.BindingSource(this.components);
            this.data = new winform.data();
            this.tab2BindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.tab2TableAdapter = new winform.Database1DataSet1TableAdapters.tab2TableAdapter();
            this.database1DataSet2 = new winform.Database1DataSet2();
            this.tab2BindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this.tab2TableAdapter1 = new winform.Database1DataSet2TableAdapters.tab2TableAdapter();
            this.tab2BindingSource2 = new System.Windows.Forms.BindingSource(this.components);
            this.tab2TableAdapter2 = new winform.dataTableAdapters.tab2TableAdapter();
            this.tab2BindingSource4 = new System.Windows.Forms.BindingSource(this.components);
            this.database1DataSet3 = new winform.Database1DataSet3();
            this.tab2BindingSource5 = new System.Windows.Forms.BindingSource(this.components);
            this.tab2TableAdapter3 = new winform.Database1DataSet3TableAdapters.tab2TableAdapter();
            this.Code = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.side_number = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.flightdestinationDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.number_of_tickets_sold = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.cost_of_one_ticket = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridView3 = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tab1BindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.database1DataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.database1DataSet1BindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.database1DataSet1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tab2BindingSource3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.data)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tab2BindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.database1DataSet2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tab2BindingSource1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tab2BindingSource2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tab2BindingSource4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.database1DataSet3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tab2BindingSource5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView3)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.кодDataGridViewTextBoxColumn,
            this.sidenumberDataGridViewTextBoxColumn,
            this.aircraftbrandDataGridViewTextBoxColumn,
            this.numberofseatsDataGridViewTextBoxColumn});
            this.dataGridView1.DataSource = this.tab1BindingSource;
            this.dataGridView1.Location = new System.Drawing.Point(12, 12);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(443, 211);
            this.dataGridView1.TabIndex = 0;
            // 
            // кодDataGridViewTextBoxColumn
            // 
            this.кодDataGridViewTextBoxColumn.DataPropertyName = "Код";
            this.кодDataGridViewTextBoxColumn.HeaderText = "Код";
            this.кодDataGridViewTextBoxColumn.Name = "кодDataGridViewTextBoxColumn";
            // 
            // sidenumberDataGridViewTextBoxColumn
            // 
            this.sidenumberDataGridViewTextBoxColumn.DataPropertyName = "side_number";
            this.sidenumberDataGridViewTextBoxColumn.HeaderText = "side_number";
            this.sidenumberDataGridViewTextBoxColumn.Name = "sidenumberDataGridViewTextBoxColumn";
            // 
            // aircraftbrandDataGridViewTextBoxColumn
            // 
            this.aircraftbrandDataGridViewTextBoxColumn.DataPropertyName = "aircraft_brand";
            this.aircraftbrandDataGridViewTextBoxColumn.HeaderText = "aircraft_brand";
            this.aircraftbrandDataGridViewTextBoxColumn.Name = "aircraftbrandDataGridViewTextBoxColumn";
            // 
            // numberofseatsDataGridViewTextBoxColumn
            // 
            this.numberofseatsDataGridViewTextBoxColumn.DataPropertyName = "number_of_seats";
            this.numberofseatsDataGridViewTextBoxColumn.HeaderText = "number_of_seats";
            this.numberofseatsDataGridViewTextBoxColumn.Name = "numberofseatsDataGridViewTextBoxColumn";
            // 
            // tab1BindingSource
            // 
            this.tab1BindingSource.DataMember = "tab1";
            this.tab1BindingSource.DataSource = this.database1DataSet;
            // 
            // database1DataSet
            // 
            this.database1DataSet.DataSetName = "Database1DataSet";
            this.database1DataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Location = new System.Drawing.Point(472, 37);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(219, 186);
            this.listBox1.TabIndex = 1;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(703, 10);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(104, 23);
            this.button1.TabIndex = 2;
            this.button1.Text = "Вывод данных";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(472, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(113, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Введите кол-во мест";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(591, 12);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 20);
            this.textBox1.TabIndex = 4;
            // 
            // listBox2
            // 
            this.listBox2.FormattingEnabled = true;
            this.listBox2.Location = new System.Drawing.Point(472, 239);
            this.listBox2.Name = "listBox2";
            this.listBox2.Size = new System.Drawing.Size(219, 212);
            this.listBox2.TabIndex = 5;
            // 
            // database1DataSet1BindingSource
            // 
            this.database1DataSet1BindingSource.DataSource = this.database1DataSet1;
            this.database1DataSet1BindingSource.Position = 0;
            // 
            // database1DataSet1
            // 
            this.database1DataSet1.DataSetName = "Database1DataSet1";
            this.database1DataSet1.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // tab1TableAdapter
            // 
            this.tab1TableAdapter.ClearBeforeFill = true;
            // 
            // dataGridView2
            // 
            this.dataGridView2.AutoGenerateColumns = false;
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Code,
            this.side_number,
            this.flightdestinationDataGridViewTextBoxColumn,
            this.number_of_tickets_sold,
            this.cost_of_one_ticket});
            this.dataGridView2.DataSource = this.tab2BindingSource5;
            this.dataGridView2.Location = new System.Drawing.Point(12, 239);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.Size = new System.Drawing.Size(443, 211);
            this.dataGridView2.TabIndex = 6;
            // 
            // tab2BindingSource3
            // 
            this.tab2BindingSource3.DataMember = "tab2";
            this.tab2BindingSource3.DataSource = this.data;
            // 
            // data
            // 
            this.data.DataSetName = "data";
            this.data.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // tab2BindingSource
            // 
            this.tab2BindingSource.DataMember = "tab2";
            this.tab2BindingSource.DataSource = this.database1DataSet1BindingSource;
            // 
            // tab2TableAdapter
            // 
            this.tab2TableAdapter.ClearBeforeFill = true;
            // 
            // database1DataSet2
            // 
            this.database1DataSet2.DataSetName = "Database1DataSet2";
            this.database1DataSet2.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // tab2BindingSource1
            // 
            this.tab2BindingSource1.DataMember = "tab2";
            this.tab2BindingSource1.DataSource = this.database1DataSet2;
            // 
            // tab2TableAdapter1
            // 
            this.tab2TableAdapter1.ClearBeforeFill = true;
            // 
            // tab2BindingSource2
            // 
            this.tab2BindingSource2.DataMember = "tab2";
            this.tab2BindingSource2.DataSource = this.database1DataSet2;
            // 
            // tab2TableAdapter2
            // 
            this.tab2TableAdapter2.ClearBeforeFill = true;
            // 
            // tab2BindingSource4
            // 
            this.tab2BindingSource4.DataMember = "tab2";
            this.tab2BindingSource4.DataSource = this.database1DataSet1BindingSource;
            // 
            // database1DataSet3
            // 
            this.database1DataSet3.DataSetName = "Database1DataSet3";
            this.database1DataSet3.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // tab2BindingSource5
            // 
            this.tab2BindingSource5.DataMember = "tab2";
            this.tab2BindingSource5.DataSource = this.database1DataSet3;
            // 
            // tab2TableAdapter3
            // 
            this.tab2TableAdapter3.ClearBeforeFill = true;
            // 
            // Code
            // 
            this.Code.DataPropertyName = "Код";
            this.Code.HeaderText = "Код";
            this.Code.Name = "Code";
            // 
            // side_number
            // 
            this.side_number.DataPropertyName = "side_number";
            this.side_number.HeaderText = "side_number";
            this.side_number.Name = "side_number";
            // 
            // flightdestinationDataGridViewTextBoxColumn
            // 
            this.flightdestinationDataGridViewTextBoxColumn.DataPropertyName = "flight_destination";
            this.flightdestinationDataGridViewTextBoxColumn.HeaderText = "flight_destination";
            this.flightdestinationDataGridViewTextBoxColumn.Name = "flightdestinationDataGridViewTextBoxColumn";
            // 
            // number_of_tickets_sold
            // 
            this.number_of_tickets_sold.DataPropertyName = "number_of_tickets_sold";
            this.number_of_tickets_sold.HeaderText = "number_of_tickets_sold";
            this.number_of_tickets_sold.Name = "number_of_tickets_sold";
            // 
            // cost_of_one_ticket
            // 
            this.cost_of_one_ticket.DataPropertyName = "cost_of_one_ticket";
            this.cost_of_one_ticket.HeaderText = "cost_of_one_ticket";
            this.cost_of_one_ticket.Name = "cost_of_one_ticket";
            // 
            // dataGridView3
            // 
            this.dataGridView3.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView3.Location = new System.Drawing.Point(703, 39);
            this.dataGridView3.Name = "dataGridView3";
            this.dataGridView3.Size = new System.Drawing.Size(622, 412);
            this.dataGridView3.TabIndex = 7;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1337, 459);
            this.Controls.Add(this.dataGridView3);
            this.Controls.Add(this.dataGridView2);
            this.Controls.Add(this.listBox2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tab1BindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.database1DataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.database1DataSet1BindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.database1DataSet1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tab2BindingSource3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.data)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tab2BindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.database1DataSet2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tab2BindingSource1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tab2BindingSource2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tab2BindingSource4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.database1DataSet3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tab2BindingSource5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView3)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.ListBox listBox2;
        private Database1DataSet database1DataSet;
        private System.Windows.Forms.BindingSource tab1BindingSource;
        private Database1DataSetTableAdapters.tab1TableAdapter tab1TableAdapter;
        private System.Windows.Forms.BindingSource database1DataSet1BindingSource;
        private Database1DataSet1 database1DataSet1;
        public System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.DataGridView dataGridView2;
        private System.Windows.Forms.BindingSource tab2BindingSource;
        private Database1DataSet1TableAdapters.tab2TableAdapter tab2TableAdapter;
        private Database1DataSet2 database1DataSet2;
        private System.Windows.Forms.BindingSource tab2BindingSource1;
        private Database1DataSet2TableAdapters.tab2TableAdapter tab2TableAdapter1;
        private System.Windows.Forms.BindingSource tab2BindingSource2;
        private data data;
        private System.Windows.Forms.BindingSource tab2BindingSource3;
        private dataTableAdapters.tab2TableAdapter tab2TableAdapter2;
        private System.Windows.Forms.DataGridViewTextBoxColumn кодDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn sidenumberDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn aircraftbrandDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn numberofseatsDataGridViewTextBoxColumn;
        private System.Windows.Forms.BindingSource tab2BindingSource4;
        private Database1DataSet3 database1DataSet3;
        private System.Windows.Forms.BindingSource tab2BindingSource5;
        private Database1DataSet3TableAdapters.tab2TableAdapter tab2TableAdapter3;
        private System.Windows.Forms.DataGridViewTextBoxColumn Code;
        private System.Windows.Forms.DataGridViewTextBoxColumn side_number;
        private System.Windows.Forms.DataGridViewTextBoxColumn flightdestinationDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn number_of_tickets_sold;
        private System.Windows.Forms.DataGridViewTextBoxColumn cost_of_one_ticket;
        private System.Windows.Forms.DataGridView dataGridView3;
    }
}

