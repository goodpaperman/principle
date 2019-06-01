VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Form_Load()
Dim pt As New PointComp.PointObj
'Dim pt As Object
'Set pt = CreateObject("PointComp.PointObj")
pt.x = 100
pt.y = 200
pt.MoveTo 300, 400
MsgBox pt.x, vbOKOnly, pt.y
End Sub
