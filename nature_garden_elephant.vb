Public Class Form1 

Dim solarSolutions As New SolarSolutions()

'On Form Load
Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load 
    
    'Call initialize methods
    solarSolutions.InitializeForm()

End Sub

'Button click to open Solar Solutions
Private Sub btnSolarSolutions_Click(sender As Object, e As EventArgs) Handles btnSolarSolutions.Click

    solarSolutions.openSolutionsForm()

End Sub 

'Button click to open Products page
Private Sub btnProducts_Click(sender As Object, e As EventArgs) Handles btnProducts.Click 

    solarSolutions.openProductForm()

End Sub 

'Button click to open calculator
Private Sub btnCalculator_Click(sender As Object, e As EventArgs) Handles btnCalculator.Click 

    solarSolutions.openCalculatorForm()

End Sub 

'Button click to open contact page
Private Sub btnContact_Click(sender As Object, e As EventArgs) Handles btnContact.Click 

    solarSolutions.openContactForm()

End Sub 

'Button click to open blog
Private Sub btnBlog_Click(sender As Object, e As EventArgs) Handles btnBlog.Click 

    solarSolutions.openBlogForm()

End Sub 

'Button click to open about page
Private Sub btnAbout_Click(sender As Object, e As EventArgs) Handles btnAbout.Click 

    solarSolutions.openAboutForm()

End Sub 

End Class 


Public Class SolarSolutions

'Declare variables 
Dim productsForm As New ProductsForm()
Dim calculatorForm As New CalculatorForm()
Dim contactForm As New ContactForm()
Dim blogForm As New BlogForm()
Dim aboutForm As New AboutForm()

Public Sub InitializeForm() 
    'Initializing form 
    'Code here 
End Sub

Public Sub openSolutionsForm()
    'Code for opening solutionsForm
    'Code here
End Sub

Public Sub openProductForm()
    'Code for opening productsForm
    productsForm.ShowDialog()
End Sub

Public Sub openCalculatorForm()
    'Code for opening calculatorForm
    calculatorForm.ShowDialog()
End Sub

Public Sub openContactForm()
    'Code for opening contactForm
    contactForm.ShowDialog()
End Sub

Public Sub openBlogForm()
    'Code for opening blogForm
    blogForm.ShowDialog()
End Sub

Public Sub openAboutForm()
    'Code for opening aboutForm
    aboutForm.ShowDialog()
End Sub

End Class