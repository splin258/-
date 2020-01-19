using System;
using System.Collections.Generic;

namespace Aaaaa_8_lab_blet
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите вашу строку:");
            string line = Console.ReadLine();
            List<string> splitLine = get_words(line);

            string new_line = update_list(splitLine, 'a', 2);

            Console.WriteLine(new_line);
        }

        static string update_list(List<string> list, char symboll, int n)
        {
            string upd = "";

            foreach(string word in list)
            {
                int num = 0;
                int pos = 0;
                string buff = "";

                while ((pos = word.IndexOf(symboll, pos)) > -1)
                {
                    num++;
                    pos += 1;

                    if(num == n)
                    {
                        buff = word.Remove(pos - 1, 1);
                        upd += buff + " ";
                        buff = "";
                        break;
                    }
                }
            }

            return upd;
        }

        static List<string> get_words(string text)
        {
            List<string> list = new List<string>();
            string buff = "";

            foreach(char c in text)
            {
                if(c != ' ')
                {
                    buff += c;
                }
                else
                {
                    if (buff != "")
                    {
                        list.Add(buff);
                    }

                    buff = "";
                }
            }

            if (buff != "")
            {
                list.Add(buff);
            }

            return list;
        }
    }
}
