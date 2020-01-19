using System;
using System.Collections.Generic;

namespace Blet_7
{
    class Program
    {
        static void Main(string[] args)
        {
            DynamicList list = new DynamicList();

            if (list.getListInConsole())
            {
                list.sortedList();
                list.showList();
            }
        }
    }

    class DynamicList
    {
        public DynamicList()
        {
            this._list = new List<int>();
        }
        public DynamicList(List<int> list)
        {
            this._list = list;            
        }
        public bool getListInConsole()
        {
            List<int> list = new List<int>();

            Console.WriteLine("Введите ваши числа:");
            string line = Console.ReadLine();
            string[] splitLine = line.Split(' ');

            foreach(var el in splitLine)
            {
                try
                {
                    list.Add(int.Parse(el));
                }
                catch
                {
                    Console.WriteLine("Ошибка ввода!");
                    return false;
                }
            }

            this._list = list;

            return true;
        }
        public void sortedList()
        {
            List<int> list = this._list;
            List<int> new_list = new List<int>();

            while(list.Count != 0)
            {
                int min_element = this.minElement(list);
                int max_element = this.maxElement(list);

                if(min_element != max_element)
                {
                    new_list.Add(max_element);
                    new_list.Add(min_element);

                    list.Remove(max_element);
                    list.Remove(min_element);
                }
                else
                {
                    new_list.Add(max_element);
                    list.Remove(max_element);
                }
            }

            this._list = new_list;
        }
        public void showList()
        {
            Console.WriteLine("List:");

            foreach(var el in this._list)
            {
                Console.WriteLine(el);
            }
        }
        private int minElement(List<int> list)
        {
            int min_element = list[0];

            foreach(int el in list)
            {
                if (min_element > el)
                {
                    min_element = el;
                }
            }

            return min_element;
        }

        private int maxElement(List<int> list)
        {
            int max_element = list[0];

            foreach (int el in list)
            {
                if (max_element < el)
                {
                    max_element = el;
                }
            }

            return max_element;
        }
        private List<int> _list { get; set; }
    }
}
