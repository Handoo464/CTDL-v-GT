using System;
using System.Collections.Generic;

namespace Selection_Sort_SV
{
    class SinhVien
    {
        //fields
        private string hoten;
        private int mssv;
        private double dtb;
        //constructors
        public SinhVien()
        {
            this.hoten = "";
            this.mssv = 0;
            this.dtb = 0;
        }
        public SinhVien(int mssv, string hoten, double dtb)
        {
            this.mssv = mssv;
            this.hoten = hoten;
            this.dtb = dtb;
        }
        //Properties

        public string Hoten { get => this.hoten; set => this.hoten = value; }
        public int Mssv { get => this.mssv; set => this.mssv = value; }
        public double Dtb { get => this.dtb; set => this.dtb = value; }
        //Methods
        public void Nhap()
        {
            Console.Write("Nhap Ho va Ten: ");
            this.hoten = Console.ReadLine();
            Console.Write("Nhap MSSV: ");
            this.mssv = int.Parse(Console.ReadLine());
            Console.Write("Nhap Diem trung binh: ");
            this.dtb = double.Parse(Console.ReadLine());
        }
        public void Xuat()
        {
            Console.WriteLine("Ho ten: {0}", this.hoten);
            Console.WriteLine("MSSV: {0}", this.mssv);
            Console.WriteLine("Diem trung binh: {0}", this.dtb);
        }
    }
    class Program
    {
        public static void Nhap(List<SinhVien> DSSV)
        {
            Console.WriteLine("Nhap so luong sinh vien: ");
            int n = int.Parse(Console.ReadLine());
            Console.WriteLine("Nhap {0} Sinh Vien muon sap xep: ", n);
            for (int i = 0; i < n; i++)
            {
                SinhVien SV = new SinhVien();
                SV.Nhap();
                DSSV.Add(SV);
            }
        }
        public static void Xuat(List<SinhVien> DSSV)
        {
            Console.WriteLine("----------Sau khi sap xep----------");
            for (int i = 0; i < DSSV.Count; i++)
            {
                DSSV[i].Xuat();
            }
        }
        public static void SelectionSort(List<SinhVien> DSSV)
        {
            for (int i = 1; i < DSSV.Count; i++)
            {
                int l, r, m;
                SinhVien x = new SinhVien();
                l = 0;
                r = i - 1;
                x = DSSV[i];
                while (l <= r)
                {
                    m = (l + r) / 2;
                    if (DSSV[m].Dtb > x.Dtb) r = m - 1;
                    else l = m + 1;
                }
                for (int j = i; j > l; j--)
                    DSSV[j] = DSSV[j - 1];
                DSSV[l] = x;
            }
            for (int i = 0; i < DSSV.Count - 1; i++)
            {
                if (DSSV[i].Dtb == DSSV[i + 1].Dtb)
                {
                    if (DSSV[i].Mssv > DSSV[i + 1].Mssv)
                    {
                        SinhVien Temp = DSSV[i];
                        DSSV[i] = DSSV[i+1];
                        DSSV[i+1] = Temp;

                    }
                }
            }
        }
        public static void Main(string[] args)
        {
            List<SinhVien> DSSV = new List<SinhVien>();
            Nhap(DSSV);
            SelectionSort(DSSV);
            Xuat(DSSV);
        }
    }
}


