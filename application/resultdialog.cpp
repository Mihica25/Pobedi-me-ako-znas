#include "resultdialog.h"
#include "ui_resultdialog.h"

ResultDialog::ResultDialog (QWidget *parent) : QDialog (parent)
{
  mainLayout = new QVBoxLayout (this);

  setWindowTitle ("Best Results");
  setFixedSize (250, 300);

  setLayout (mainLayout);
}

ResultDialog::~ResultDialog () {}

void
ResultDialog::clearLayout (QLayout *layout)
{
  QLayoutItem *item;
  while ((item = layout->takeAt (0)) != nullptr)
	{
	  delete item->widget ();
	  delete item;
	}
}

void
ResultDialog::showResults (QString &data)
{
  clearLayout (mainLayout);

  QVector<ResultDialog::GameResult> results = parseBestResults (data);
  QString resultText;
  for (const auto &result : results)
	{
	  resultText += QString ("%1 vs %2 - %3:%4\n")
						.arg (result.player1Name)
						.arg (result.player2Name)
						.arg (result.player1Points)
						.arg (result.player2Points);
	}

  QLabel *resultLabel = new QLabel (resultText, this);
  QFont font ("Arial", 14);
  resultLabel->setFont (font);
  mainLayout->addWidget (resultLabel);

  exec ();
}

QVector<ResultDialog::GameResult>
ResultDialog::parseBestResults (QString &data)
{
  QVector<ResultDialog::GameResult> results;

  if (!data.startsWith ("BEST_RESULTS:"))
	{
	  qDebug () << "Invalid data format";
	  return results;
	}

  QString resultsData = data.mid (QString ("BEST_RESULTS:").length ());

  QStringList resultList = resultsData.split ("\n");

  for (const QString &resultStr : resultList)
	{
	  QStringList resultData = resultStr.split (",");

	  if (resultData.size () == 5)
		{
		  ResultDialog::GameResult result;
		  result.player1Name = resultData[0];
		  result.player1Points = resultData[1].toInt ();
		  result.player2Name = resultData[2];
		  result.player2Points = resultData[3].toInt ();
		  result.dateTime
			  = QDateTime::fromString (resultData[4], "yyyy-MM-ddTHH:mm:ss");

		  results.append (result);
		}
	  else
		{
		  qDebug () << "Invalid result data format:" << resultStr;
		}
	}

  return results;
}
