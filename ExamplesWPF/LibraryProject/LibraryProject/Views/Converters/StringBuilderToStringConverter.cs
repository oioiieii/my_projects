using System.Globalization;
using System.Text;
using System.Windows.Controls;
using System.Windows.Data;

namespace LibraryProject.WPF.Views.Converters
{
    class StringBuilderToStringConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value is StringBuilder sb) return sb.ToString();
            return string.Empty;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value is string str) return new StringBuilder(str);
            return new StringBuilder();
        }
    }
}
