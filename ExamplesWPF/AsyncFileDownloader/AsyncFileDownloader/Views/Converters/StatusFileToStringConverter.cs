using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Data;
using static AsyncFileDownloader.ViewModels.MainWinodwViewModel;

namespace AsyncFileDownloader.Views.Converters
{
    class StatusFileToStringConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if(value is StatusFile status)
            {
                if (status == StatusFile.Waiting) return "Ожидает";
                else if (status == StatusFile.Loading) return "Загружается";
                else if (status == StatusFile.Completed) return "Скачан";
            }
            return string.Empty;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}
