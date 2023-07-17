Public Class frmSolarSolutions

'Form Load Event
Private Sub frmSolarSolutions_Load(sender As Object, e As EventArgs) Handles MyBase.Load

'Set Form Caption
Me.Text = "Solar Solutions"

'Set Form Color
Me.BackColor = Color.SkyBlue

End Sub

'Button1 Click Event
Private Sub btnCalculate_Click(sender As Object, e As EventArgs) Handles btnCalculate.Click

'Declare Variables
Dim watts As Double
Dim hours As Double
Dim total As Double

'Read user input
watts = txtWatts.Text
hours = txtHours.Text

'Calculate total
total = watts * hours

'Display result
lblResult.Text = total & " Watts/Hour"

End Sub

'Button2 Click Event
Private Sub btnClear_Click(sender As Object, e As EventArgs) Handles btnClear.Click

'Clear Textboxes
txtWatts.Text = ""
txtHours.Text = ""

'Clear Labels
lblResult.Text = ""

End Sub

'Timer Event
Private Sub tmrSolarSolutions_Tick(sender As Object, e As EventArgs) Handles tmrSolarSolutions.Tick

'Declare Variable and Read Time
Dim time As DateTime = DateTime.Now

'Display Time
lblTime.Text = time.ToString("hh:mm:ss tt")

End Sub

End Class