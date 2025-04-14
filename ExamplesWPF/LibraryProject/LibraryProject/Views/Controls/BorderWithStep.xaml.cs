using System.Windows;
using System.Windows.Controls;

namespace LibraryProject.WPF.Views.Controls
{
    /// <summary>
    /// Логика взаимодействия для StackPanelWithStep.xaml
    /// </summary>
    public partial class BorderWithStep : UserControl
    {
        public BorderWithStep()
        {
            InitializeComponent();
        }

        public int NumStep
        {
            get { return (int)GetValue(NumStepProperty); }
            set { SetValue(NumStepProperty, value); }
        }

        // Using a DependencyProperty as the backing store for NumStep.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty NumStepProperty =
            DependencyProperty.Register("NumStep", typeof(int), typeof(BorderWithStep), new PropertyMetadata(0));

        public new object Content
        {
            get { return (object)GetValue(ContentProperty); }
            set { SetValue(ContentProperty, value); }
        }

        public static new readonly DependencyProperty ContentProperty =
            DependencyProperty.Register("Content", typeof(object), typeof(BorderWithStep), new PropertyMetadata(null));

    }
}
